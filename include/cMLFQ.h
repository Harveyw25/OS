#ifndef CMLFQ_H
#define CMLFQ_H
#include "Execution.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include "Globals.h"
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "cDeletePCB.h"
#include "cShowPCB.h"
#include "cUnblock.h"
#include <queue>
#include <vector>

class cMLFQ : public Execution
{
    public:
        public:
        virtual void execute();
        void addToUserBlockedQueue(PCB*, std::ofstream&, int);
        void addToIOBlockedQueue(PCB*, std::ofstream&, int);


    protected:

    private:
};

#endif // CMLFQ_H
