#include "CommandList.h"

CommandList::CommandList()
{

}

int CommandList::addCommand(std::string cmd)
{
    //this is ugly and needs hope
    CommandTable table;

    int codeForCommand = table.getCommandCode(cmd);

    if(codeForCommand != 0)
    {
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
                }
                break;
            case 8:
                {
                    e = new cHelp;
                }
        }

        e->execute();
        List.push_back(cmd);
    }
    return 1;
}

std::vector <std::string> CommandList::getList()
{
    return List;
}
