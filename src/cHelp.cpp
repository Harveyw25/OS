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
    currentCommand = table.getCommandName(9);
    textList.push_back(currentCommand + " - creates a PCB and inserts it into the ready queue");
    currentCommand = table.getCommandName(10);
    textList.push_back(currentCommand + " - deletes a user specified PCB");
    currentCommand = table.getCommandName(11);
    textList.push_back(currentCommand + " - transfers a user specified PCB from the ready queue to the blocked queue");
    currentCommand = table.getCommandName(12);
    textList.push_back(currentCommand + " - transfers a user specified PCB from the blocked queue to the ready queue");
    currentCommand = table.getCommandName(13);
    textList.push_back(currentCommand + " - shows information about a user specified PCB");
    currentCommand = table.getCommandName(14);
    textList.push_back(currentCommand + " - shows information about all PCBs");
    currentCommand = table.getCommandName(15);
    textList.push_back(currentCommand + " - shows information about PCBs in the ready queue");
    currentCommand = table.getCommandName(16);
    textList.push_back(currentCommand + " - shows information about PCBs in the blocked queue");
    currentCommand = table.getCommandName(17);
    textList.push_back(currentCommand + " - generates a user specified number of PCBs randomly");
    currentCommand = table.getCommandName(18);
    textList.push_back(currentCommand + " - simulates an Operating System's handling of PCBs using a Random Round Robin algorithm");
    currentCommand = table.getCommandName(19);
    textList.push_back(currentCommand + " - simulates an Operating System's handling of PCBs using a Round Robin algorithm");
    currentCommand = table.getCommandName(20);
    textList.push_back(currentCommand + " - simulates an Operating System's handling of PCBs using a Multi-Level Feedback Queue");
    currentCommand = table.getCommandName(21);
    textList.push_back(currentCommand + " - simulates an Operating System's handling of PCBs using all three algorithms and compares them");

    Interface i;
    i.printToScrn(textList);
}
