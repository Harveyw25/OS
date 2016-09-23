#include "cCreatePCB.h"

void cCreatePCB::getPCB(int id, int mem)
{
    PCBtoAdd = new PCB(id, mem);

    for(int i = 0; i < PCBList.size(); i++)
    {
        if(id == PCBList.at(i)->getPID())
        {
            invalid = true;
        }
    }

    if(mem > currentMemory)
    {
        invalid = true;
    }
}

void cCreatePCB::execute()
{
    if(invalid == true)
    {
        std::cout << "Invalid PCB" << std::endl;
    }
    else
    {
        bool added = false;

        readyQueue.push(PCBtoAdd);

        if(PCBList.size() == 0)
        {
            PCBList.push_back(PCBtoAdd);
            added = true;
        }
        else
        {
            for(int i = 0; i < PCBList.size(); i++)
            {
                if(PCBtoAdd->getPID() < PCBList.at(i)->getPID())
                {
                    PCBList.insert(PCBList.begin()+i, PCBtoAdd);
                    added = true;

                    break;
                }
            }
        }

        if(added == false)
        {
            PCBList.push_back(PCBtoAdd);
        }
    }
}
