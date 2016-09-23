#include "cGeneratePCB.h"

void cGeneratePCB::execute()
{
    srand(time(NULL));

    for(int i = 0; i < num; i++)
    {
        int id = rand() % 9999999999 + 1;
        int mem = rand() % currentMemory + 1;

        cCreatePCB PCBtoAdd;
        PCBtoAdd.getPCB(id, mem);
        PCBtoAdd.execute();
    }
}

void cGeneratePCB::getNum(int NUM)
{
    num = NUM;
}
