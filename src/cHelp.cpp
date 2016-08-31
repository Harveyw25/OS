#include "cHelp.h"

void cHelp::execute()
{
    std::vector <std::string> textList;
    CommandTable table;
    std::string currentCommand = "";

    textList.push_back("*** Help Menu ***");
    currentCommand = table.getCommandName(1);
    textList.push_back(currentCommand + " - display current software version");
    currentCommand = table.getCommandName(2);
    textList.push_back(currentCommand + " - display the current date");
    currentCommand = table.getCommandName(3);
    textList.push_back(currentCommand + " - display the files in the OS directory files folder");
    currentCommand = table.getCommandName(4);
    textList.push_back(currentCommand + " - display previously entered commands");
    currentCommand = table.getCommandName(5);
    textList.push_back(currentCommand + " - run a bat file");
    currentCommand = table.getCommandName(6);
    textList.push_back(currentCommand + " - rename a function");
    currentCommand = table.getCommandName(7);
    textList.push_back(currentCommand + " - exit the OS");

    Interface i;
    i.printToScrn(textList);
}
