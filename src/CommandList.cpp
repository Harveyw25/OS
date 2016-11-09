#include "CommandList.h"

CommandList::CommandList()
{

}

int CommandList::addCommand(std::string cmd)
{
    CommandTable table;

    int codeForCommand = table.getCommandCode(cmd);


    Execution *e;
    Interface i;
    switch(codeForCommand)
    {
        case 1:
            {
                e = new cVersion;
                break;
            }
        case 2:
            {
                e = new cDate;
                break;
            }
        case 3:
            {
                e = new cDirectory;
                break;
            }
        case 4:
            {
                cHistory* hist = new cHistory();
                hist->setList(List);
                e = hist;
                break;
            }
        case 5:
            {
                e = new cBatch;
                break;
            }

        case 6:
            {
                std::string nameToChange = "";
                std::string newName = "";

                std::cout << "Which command would you like to rename? - ";
                std::cin >> nameToChange;
                std::cout << "What would you like to rename it to? - ";
                std::cin >> newName;

                CommandTable t;
                t.renameCommand(nameToChange, newName);
                e = new cAliasing;
                break;
            }

        case 7:
            {
                std::cout << "Exit? (y or n)" << std::endl;
                std::string confirmation = "";
                std::cin >> confirmation;

                if(confirmation == "y")
                {
                    return 0;
                }
                e = new cExit();
                break;
            }
        case 8:
            {
                e = new cHelp;
                break;
            }
        case 9:
            {
                int id, mem, type;
                std::cout << "Enter an ID: ";
                std::cin >> id;
                std::cout << "Enter how much memory to assign: ";
                std::cin >> mem;
                std::cout << "What kind of process is it? (0 = Mixed, 1 = Interactive, 2 = CPU Bound): ";
                std::cin >> type;
                cCreatePCB* temp = new cCreatePCB();
                temp->getPCB(id, mem, type);
                e = temp;
                break;
            }
        case 10:
            {
                int id;
                std::cout << "Enter an ID: ";
                std::cin >> id;
                cDeletePCB* temp = new cDeletePCB();
                temp->getID(id);
                e = temp;
                break;
            }
        case 11:
            {
                int id;
                std::cout << "Enter an ID: ";
                std::cin >> id;

                cBlock* temp = new cBlock();
                temp->getID(id);
                e = temp;
                break;
            }
        case 12:
            {
                int id;
                std::cout << "Enter an ID: ";
                std::cin >> id;

                cUnblock* temp = new cUnblock();
                temp->getID(id);
                e = temp;
                break;
            }
        case 13:
            {
                int id;
                std::cout << "Enter an ID: ";
                std::cin >> id;

                cShowPCB* temp = new cShowPCB();
                temp->getID(id);
                e = temp;
                break;
            }
        case 14:
            {
                e = new cShowAll();
                break;
            }
        case 15:
            {
                e = new cShowReady();
                break;
            }
        case 16:
            {
                e = new cShowBlocked();
                break;
            }
        case 17:
            {
                int num;
                std::cout << "How many PCBs would you like to generate: ";
                std::cin >> num;

                cGeneratePCB* temp = new cGeneratePCB();
                temp->getNum(num);
                e = temp;
                break;
            }
        case 18:
            {
                e = new cRoundRobinRandom();
                break;
            }
        case 19:
            {
                e = new cRobin();
                break;
            }
        case 20:
            {
                e = new cMLFQ();
                break;
            }
        case 21:
            {
                e = new cRunAll();
                break;
            }
        case 0:
            {
                std::cout << "Invalid Command" << std::endl;
                e = new cExit();
                break;
            }
        }

        e->execute();
        List.push_back(cmd);

    return 1;
}

std::vector <std::string> CommandList::getList()
{
    return List;
}
