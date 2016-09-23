#ifndef CDELETEPCB_H
#define CDELETEPCB_H
#include "Globals.h"
#include "Execution.h"
#include <iostream>
#include <queue>

class cDeletePCB : public Execution
{
    public:
        virtual void execute();
        void getID(int);

    protected:

    private:
        int ID;
};

#endif // CDELETEPCB_H
