#ifndef CEXECUTE_H
#define CEXECUTE_H
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

class RoundRobinRandom : public Execution
{
    public:
        virtual void execute();
        void addToUserBlockedQueue(PCB*);
        void addToIOBlockedQueue(PCB*);

    protected:

    private:
};

#endif // CROUNDROBINRANDOM_H
