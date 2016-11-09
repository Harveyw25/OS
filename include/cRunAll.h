#ifndef CRUNALL_H
#define CRUNALL_H
#include "cRobin.h"
#include "cRoundRobinRandom.h"
#include "cMLFQ.h"
#include "Execution.h"
#include "Globals.h"
#include <queue>
#include <vector>
#include <iostream>
#include "cCreatePCB.h"

class cRunAll : public Execution
{
    public:
        void execute();
        void reset(std::vector<int>, std::vector<int>, std::vector<int>);

    protected:

    private:
};

#endif // CRUNALL_H
