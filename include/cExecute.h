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

class cExecute : public Execution
{
    public:
        virtual void execute();

    protected:

    private:
};

#endif // CEXECUTE_H
