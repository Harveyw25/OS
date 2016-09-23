#include "cExecute.h"

void cExecute::execute()
{
    struct event
    {
        int timeEntered;
        int type;
    };

    std::queue <event> eventQueue;
    std::ofstream logOutput;
    PCB* cpu;
    srand(time(NULL));

    remove("Log.txt");
    std::string fileName = "Log.txt";
    logOutput.open(fileName.c_str());

    int ioEventCounter = 0;
    int timeCycle = 0;
    while(!PCBList.empty())
    {
        if(!readyQueue.empty())
        {
            cpu = readyQueue.front();
            logOutput << "PCB " << cpu->getPID() << " enters the cpu" << '\n';
            readyQueue.pop();

            int cpuUsage = rand() % 10001;

            cpu->addUsageTerm(cpuUsage);

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
                    logOutput << "Termination of ID: " << cpu->getPID() << '\n';
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
            case 2:
                {
                    cpu->setTimeEnteredBlock(timeCycle);
                    cpu->setType(0);
                    blockedQueue.push(cpu);
                    logOutput << "PCB " << cpu->getPID() << " enters the blocked queue at " << timeCycle << " awaiting an user I/O request" << '\n';
                    break;
                }
            case 3:
                {
                    cpu->setTimeEnteredBlock(timeCycle);
                    cpu->setType(1);
                    blockedQueue.push(cpu);
                    logOutput << "PCB " << cpu->getPID() << " enters the blocked queue at " << timeCycle << " awaiting a hard drive I/O request" << '\n';
                    break;
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
                e.type = 0;
                eventQueue.push(e);
                logOutput << "User event created" << '\n';
            }
            else if(eventDetermine == 9)
            {
                e.type = 1;
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

            if(blockedQueue.front()->getType() != eventQueue.front().type)
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

    logOutput.close();
}
