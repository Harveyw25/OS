#include "Command.h"

Command::Command(std::string inputName, int inputCode)
{
    name = inputName;
    code = inputCode;
}

std::string Command::getName()
{
    return name;
}

int Command::getCode()
{
    return code;
}

void Command::setName(std::string newName)
{
    name = newName;
}
