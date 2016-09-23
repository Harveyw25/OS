#include "cDeletePCB.h"

void cDeletePCB::execute()
{
    bool foundPCB = false;

    for(int i = 0; i < PCBList.size(); i++)
    {
        if(PCBList.at(i)->getPID() == ID)
        {
            foundPCB = true;
            PCBList.erase(PCBList.begin() + i);
            break;
        }
    }

    if(foundPCB)
    {
        std::queue<PCB*> tempQueue;

        for(int i = readyQueue.size(); i > 0; i--)
        {
            if(ID != readyQueue.front()->getPID())
            {
                tempQueue.push(readyQueue.front());
            }
            readyQueue.pop();
        }
        readyQueue = tempQueue;

        std::queue<PCB*> temp;
        for(int i = blockedQueue.size(); i > 0; i--)
        {
            if(ID != blockedQueue.front()->getPID())
            {
                temp.push(blockedQueue.front());
            }
            blockedQueue.pop();
        }
        blockedQueue = temp;
    }
    else
    {
        std::cout << "PCB not found" << std::endl;
    }
}

void cDeletePCB::getID(int id)
{
    ID = id;
}
