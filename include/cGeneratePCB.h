#ifndef CGENERATEPCB_H
#define CGENERATEPCB_H
#include "Execution.h"
#include <stdlib.h>
#include <time.h>
#include "cCreatePCB.h"
#include "Globals.h"

class cGeneratePCB : public Execution
{
    public:
        virtual void execute();
        void getNum(int);

    protected:

    private:
        int num;
};

#endif // CGENERATEPCB_H
