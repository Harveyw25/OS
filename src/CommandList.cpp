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
                e = new cVersion;
                break;
            case 2:
                e = new cDate;
                break;
            case 3:
                e = new cDirectory;
                break;
            case 4:
                //implement this better

                i.printToScrn(List);
                e = new cHistory;
                break;
            case 5:
                {
                    //implement this better
                    std::string fileName = "";
                    std::cout << "Enter a file name" << std::endl;
                    std::cin >> fileName;
                    std::ifstream inData;
                    inData.open(fileName.c_str());
                    std::string line = "";

                    while(inData.is_open())
                    {
                        while(getline(inData, line))
                        {
                            addCommand(line);
                        }
                    }
                    inData.close();
                    e = new cBatch;
                    break;
                }

            case 6:
                {
                    //redo this
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
                //redo this
                {
                    std::cout << "Exit? (y or n)" << std::endl;
                    std::string confirmation = "";
                    std::cin >> confirmation;

                    if(confirmation == "y")
                    {
                        return 0;
                    }
                    e = new cExit;
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
