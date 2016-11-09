
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
#include "cCreatePCB.h"
#include "cDeletePCB.h"
#include "cBlock.h"
#include "cUnblock.h"
#include "cShowPCB.h"
#include "cShowAll.h"
#include "cShowReady.h"
#include "cShowBlocked.h"
#include "cRoundRobinRandom.h"
#include "cRobin.h"
#include "cMLFQ.h"
#include "cRunAll.h"
#include "cGeneratePCB.h"


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
