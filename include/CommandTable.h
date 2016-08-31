/*  TODO

    Test
*/

#ifndef COMMANDTABLE_H
#define COMMANDTABLE_H
#include <vector>
#include <fstream>
#include <iostream>
#include "Command.h"

class CommandTable
{
    public:
        CommandTable();
        void importTable();
        void exportTable();
        int getCommandCode(std::string);
        void renameCommand(std::string, std::string);
        std::string getCommandName(int);
    protected:
    private:
        std::vector <Command> Table;

};

#endif // COMMANDTABLE_H
