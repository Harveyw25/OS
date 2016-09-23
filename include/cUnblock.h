#ifndef CUNBLOCK_H
#define CUNBLOCK_H
#include "Globals.h"
#include "Execution.h"
#include <queue>
#include <iostream>
#include "PCB.h"

class cUnblock : public Execution
{
    public:
        virtual void execute();
        void getID(int);

    protected:

    private:
        int id;
};

#endif // CUNBLOCK_H
