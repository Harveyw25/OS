/*  TODO

    Test
*/

#ifndef COMMANDTABLE_H
#define COMMANDTABLE_H
#include <vector>
#include "Command.h"

class CommandTable
{
    public:
        CommandTable();
        void importTable();
        void exportTable();
        int getCommandCode(std::string name);
        void renameCommand(std::string, std::string);
    protected:
    private:
        std::vector <Command> Table;

};

#endif // COMMANDTABLE_H
