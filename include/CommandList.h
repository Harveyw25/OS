/*  TODO

    Test
*/

#ifndef COMMANDLIST_H
#define COMMANDLIST_H

#include <vector>
#include "Command.h"

class CommandList
{
    public:
        CommandList();
        void addCommand(Command);
        std::vector <Command> getList();

    protected:
    private:
        std::vector <Command> List;
};

#endif // COMMANDLIST_H
