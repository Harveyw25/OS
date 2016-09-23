#ifndef CSHOWREADY_H
#define CSHOWREADY_H
#include "Execution.h"
#include "Globals.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include "PCB.h"
#include "Interface.h"

class cShowReady : public Execution
{
    public:
        virtual void execute();

    protected:

    private:
};

#endif // CSHOWREADY_H
