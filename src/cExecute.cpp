#include "cRoundRobinRandom.h"

std::ofstream logOutput;
int timeCycle = 1;

void cRoundRobinRandom::execute()
{
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

    while(!PCBList.empty())
    {
        if(!readyQueue.empty())
        {
            timeCycle += 10;
            for(int i = 0; i < PCBList.size(); i++)
            {
                PCBList.at(i)->addWaitingTerm(10);
            }

            cpu = readyQueue.front();
            logOutput << "PCB " << cpu->getPID() << " enters the cpu at " << timeCycle << '\n';
            readyQueue.pop();

            if(cpu->getResponseTime() == 0)
            {
                cpu->setResponseTime(timeCycle);
                responseTimes.push_back(timeCycle);
            }
            int cpuUsage = rand() % 10001;

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
                    readyQueue.push(cpu);
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
                            addToUserBlockedQueue(cpu);
                        }
                        else
                        {
                            addToIOBlockedQueue(cpu);
                        }
                    }
                    else if(cpu->getType() == 1)
                    {
                        if(requestBlockedType < 3)
                        {
                            addToUserBlockedQueue(cpu);
                        }
                        else
                        {
                            addToIOBlockedQueue(cpu);
                        }
                    }
                    else
                    {
                        if(requestBlockedType < 1)
                        {
                            addToUserBlockedQueue(cpu);
                        }
                        else
                        {
                            addToIOBlockedQueue(cpu);
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
            readyQueue.push(blockedQueue.front());
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

void cRoundRobinRandom::addToIOBlockedQueue(PCB *pcbToAdd)
{
    pcbToAdd->setTimeEnteredBlock(timeCycle);
    pcbToAdd->setType(1);
    blockedQueue.push(pcbToAdd);
    logOutput << "PCB " << pcbToAdd->getPID() << " enters the blocked queue at " << timeCycle << " awaiting a hard drive I/O request" << '\n';
}

void cRoundRobinRandom::addToUserBlockedQueue(PCB* pcbToAdd)
{
    pcbToAdd->setTimeEnteredBlock(timeCycle);
    pcbToAdd->setBlockedType(0);
    blockedQueue.push(pcbToAdd);
    logOutput << "PCB " << pcbToAdd->getPID() << " enters the blocked queue at " << timeCycle << " awaiting an user I/O request" << '\n';
}
