#ifndef CCREATEPCB_H
#define CCREATEPCB_H
#include "PCB.h"
#include "Globals.h"
#include "Execution.h"
#include <iostream>

class cCreatePCB : public Execution
{
    public:
        void getPCB(int, int, int);
        virtual void execute();

    protected:

    private:
        PCB* PCBtoAdd;
        bool invalid = false;
};

#endif // CCREATEPCB_H
