#ifndef CSHOWPCB_H
#define CSHOWPCB_H

#include "Execution.h"
#include "Globals.h"
#include <iostream>

class cShowPCB : public Execution
{
    public:
        virtual void execute();
        void getID(int);

    protected:

    private:
        int id;
};

#endif // CSHOWPCB_H
