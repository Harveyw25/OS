#ifndef CBLOCK_H
#define CBLOCK_H
#include "Globals.h"
#include "Execution.h"
#include <queue>
#include <iostream>
#include "PCB.h"

class cBlock : public Execution
{
    public:
        virtual void execute();
        void getID(int);

    protected:

    private:
        int id;
};

#endif // CBLOCK_H
