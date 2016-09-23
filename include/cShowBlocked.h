#ifndef CSHOWBLOCKED_H
#define CSHOWBLOCKED_H
#include "Execution.h"
#include "Globals.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include "PCB.h"
#include "Interface.h"


class cShowBlocked : public Execution
{
    public:
        virtual void execute();

    protected:

    private:
};

#endif // CSHOWBLOCKED_H
