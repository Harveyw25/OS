#include "CommandList.h"

CommandList::CommandList()
{

}

void CommandList::addCommand(Command cmd)
{
    List.push_back(cmd);
}

std::vector <Command> CommandList::getList()
{
    return List;
}
