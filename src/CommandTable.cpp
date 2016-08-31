#include "CommandTable.h"


CommandTable::CommandTable()
{
    importTable();
}

void CommandTable::importTable()
{
    std::string fileName = "Table.txt";
    std::ifstream inData;
    inData.open(fileName.c_str());
    std::string line = "";
    int i = 0;

    if(inData.is_open())
    {
        while(getline(inData,line))
        {
            Table.push_back(Command(line, i));
            i++;
        }
    }
    else
    {
        std::cout << "Table.txt is missing" << std::endl;
    }

    inData.close();
}

void CommandTable::exportTable()
{
    std::string fileName = "Table.txt";
    std::ofstream outData;
    outData.open(fileName.c_str());

    for(int i = 0; i < Table.size(); i++)
    {
        outData << Table.at(i).getName();
        outData << '\n';
    }

    outData.close();
}

int CommandTable::getCommandCode(std::string nameToCheck)
{
    for(int i = 0; i < Table.size(); i++)
    {
        if(Table.at(i).getName() == nameToCheck)
        {
            return Table.at(i).getCode();
        }
    }

    return 0;
}

void CommandTable::renameCommand(std::string oldName, std::string newName)
{
    for(int i = 0; i < Table.size(); i++)
    {
        if(Table.at(i).getName() == oldName)
        {
            Table.at(i).setName(newName);
            break;
        }
    }

    exportTable();
}

std::string CommandTable::getCommandName(int code)
{
    return Table.at(code).getName();
}
