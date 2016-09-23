#include "cShowPCB.h"

void cShowPCB::execute()
{
    bool found = false;
    for(int i = 0; i < PCBList.size(); i++)
    {
        if(PCBList.at(i)->getPID() == id)
        {
            found = true;
            std::cout << "ID: " << PCBList.at(i)->getPID()
            << " Usage: " << PCBList.at(i)->getUsageTerm()
            << " Request: " << PCBList.at(i)->getRequestTerm()
            << " Waiting: " << PCBList.at(i)->getWaitingTerm()
            << " Memory: " << PCBList.at(i)->getMemory() << std::endl;
        }
    }
    if(!found)
    {
        std::cout << "PCB not found" <<std::endl;
    }
}

void cShowPCB::getID(int ID)
{
    id = ID;
}
