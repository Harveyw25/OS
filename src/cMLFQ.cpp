#include "cMLFQ.h"

void cMLFQ::execute()
{
    std::ofstream logOutput;
    int timeCycle = 1;

    struct event
    {
        int timeEntered;
        int BlockedType;
    };

    std::queue <event> eventQueue;
    std::vector <int> turnAroundTimes;
    std::vector <int> responseTimes;
    float cpuUsageTotal = 0;
    PCB* cpu;
    srand(time(NULL));
    remove("Log.txt");
    std::string fileName = "Log.txt";
    logOutput.open(fileName.c_str());
    int ioEventCounter = 0;
    int cpuUsage;
    int threads;

    std::cout << "Enter a time quantum: ";
    std::cin >> cpuUsage;
    std::cout << "Enter the amount of threads: ";
    std::cin >> threads;

    std::queue<PCB*> readyQueueList [threads];
    readyQueueList[0] = readyQueue;
    readyQueue = std::queue<PCB*>();

    for(int i = 0; i < PCBList.size(); i++)
    {
        PCBList.at(i)->setTier(0);
    }

    while(!PCBList.empty())
    {
        bool readyPCB = false;
        int highestTier = 0;

        for(int i = threads-1; i > -1; i--)
        {
            if(!readyQueueList[i].empty())
            {
                readyPCB = true;
                highestTier = i;
            }
        }

        if(readyPCB)
        {
            timeCycle += 10;
            for(int i = 0; i < PCBList.size(); i++)
            {
                PCBList.at(i)->addWaitingTerm(10);
            }

            cpu = readyQueueList[highestTier].front();
            logOutput << "PCB " << cpu->getPID() << " enters the cpu at " << timeCycle << '\n';
            readyQueueList[highestTier].pop();

            if(cpu->getResponseTime() == 0)
            {
                cpu->setResponseTime(timeCycle);
                responseTimes.push_back(timeCycle);
            }

            cpu->addUsageTerm(cpuUsage);
            timeCycle += cpuUsage;
            cpuUsageTotal += cpuUsage;

            for(int i = 0; i < PCBList.size(); i++)
            {
                if(cpu->getPID() != PCBList.at(i)->getPID())
                {
                    PCBList.at(i)->addWaitingTerm(cpuUsage);
                }
            }

            int processFate = rand() % 4;

            switch(processFate)
            {
            case 0:
                {
                    logOutput << "Termination of ID: " << cpu->getPID() << " at " << timeCycle << '\n';
                    cpu->setTurnAround(timeCycle - cpu->getResponseTime());
                    turnAroundTimes.push_back(timeCycle - cpu->getResponseTime());
                    cShowPCB shower;
                    shower.getID(cpu->getPID());
                    shower.execute();
                    cDeletePCB del;
                    del.getID(cpu->getPID());
                    del.execute();
                    break;
                }
            case 1:
                {
                    if(highestTier+1 == threads)
                    {
                        readyQueueList[highestTier].push(cpu);
                    }
                    else
                    {
                        readyQueueList[highestTier+1].push(cpu);
                        cpu->setTier(highestTier+1);
                        logOutput << "PCB " << cpu->getPID() << " gets demoted to tier " <<  highestTier+1 << '\n';
                    }
                    logOutput << "PCB " << cpu->getPID() << " enters ready queue at " <<  timeCycle << '\n';
                    break;
                }
            case 2: case 3:
                {
                    int requestBlockedType = rand() % 4;

                    if(cpu->getType() == 0)
                    {
                        if(requestBlockedType < 2)
                        {
                            addToUserBlockedQueue(cpu, logOutput, timeCycle);
                        }
                        else
                        {
                            addToIOBlockedQueue(cpu, logOutput, timeCycle);
                        }
                    }
                    else if(cpu->getType() == 1)
                    {
                        if(requestBlockedType < 3)
                        {
                            addToUserBlockedQueue(cpu, logOutput, timeCycle);
                        }
                        else
                        {
                            addToIOBlockedQueue(cpu, logOutput, timeCycle);
                        }
                    }
                    else
                    {
                        if(requestBlockedType < 1)
                        {
                            addToUserBlockedQueue(cpu, logOutput, timeCycle);
                        }
                        else
                        {
                            addToIOBlockedQueue(cpu, logOutput, timeCycle);
                        }
                    }

                }
            }
        }

        if(ioEventCounter == 9)
        {
            ioEventCounter = 0;

            event e;
            e.timeEntered = timeCycle;

            int eventDetermine = rand() % 11;

            if(eventDetermine == 4)
            {
                e.BlockedType = 0;
                eventQueue.push(e);
                logOutput << "User event created" << '\n';
            }
            else if(eventDetermine == 9)
            {
                e.BlockedType = 1;
                eventQueue.push(e);
                logOutput << "Hard Drive event created" << '\n';
            }
        }

        bool continueSearching = true;

        while(!eventQueue.empty() && eventQueue.front().timeEntered < blockedQueue.front()->getTimeEnteredBlock())
        {
            eventQueue.pop();
        }

        while(continueSearching && !blockedQueue.empty() && !eventQueue.empty())
        {

            if(blockedQueue.front()->getBlockedType() != eventQueue.front().BlockedType)
            {
                continueSearching = false;
            }

            logOutput << "Event satisfied ID: " << blockedQueue.front()->getPID() << "'s request -> moved to ready queue" << '\n';
            blockedQueue.front()->addRequestTerm(timeCycle - blockedQueue.front()->getTimeEnteredBlock());
            readyQueueList[blockedQueue.front()->getTier()].push(blockedQueue.front());
            blockedQueue.pop();
            eventQueue.pop();
        }

        ioEventCounter++;
        timeCycle++;
    }

    int averageTurnAround = 0;
    int averageResponse = 0;

    for(int i = 0; i < turnAroundTimes.size(); i++)
    {
        averageTurnAround += turnAroundTimes.at(i);
    }
    averageTurnAround = averageTurnAround / turnAroundTimes.size();

    for(int i = 0; i < responseTimes.size(); i++)
    {
        averageResponse += responseTimes.at(i);
    }
    averageResponse = averageResponse / responseTimes.size();

    std::cout << "CPU Usage Percent: " << cpuUsageTotal / timeCycle << std::endl;
    std::cout << "Average Turn Around Time: " << averageTurnAround << std::endl;
    std::cout << "Average Response Time: " << averageResponse << std::endl;

    logOutput.close();
}

void cMLFQ::addToIOBlockedQueue(PCB *pcbToAdd, std::ofstream& logOutput, int timeCycle)
{
    pcbToAdd->setTimeEnteredBlock(timeCycle);
    pcbToAdd->setType(1);
    blockedQueue.push(pcbToAdd);
    logOutput << "PCB " << pcbToAdd->getPID() << " enters the blocked queue at " << timeCycle << " awaiting a hard drive I/O request" << '\n';
}

void cMLFQ::addToUserBlockedQueue(PCB* pcbToAdd, std::ofstream& logOutput, int timeCycle)
{
    pcbToAdd->setTimeEnteredBlock(timeCycle);
    pcbToAdd->setBlockedType(0);
    blockedQueue.push(pcbToAdd);
    logOutput << "PCB " << pcbToAdd->getPID() << " enters the blocked queue at " << timeCycle << " awaiting an user I/O request" << '\n';
}
