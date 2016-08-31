/*  TODO

    Test
*/

#ifndef COMMANDLIST_H
#define COMMANDLIST_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "Execution.h"
#include "CommandTable.h"
#include "cVersion.h"
#include "cDirectory.h"
#include "cDate.h"
#include "cHistory.h"
#include "Interface.h"
#include "cBatch.h"
#include "cAliasing.h"
#include "cExit.h"
#include "cHelp.h"

class CommandList
{
    public:
        CommandList();
        int addCommand(std::string);
        std::vector <std::string> getList();
    protected:
    private:
        std::vector <std::string> List;
};

#endif // COMMANDLIST_H
