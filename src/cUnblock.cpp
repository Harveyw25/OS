#include "cUnblock.h"

void cUnblock::execute()
{
    std::queue<PCB*> temp;
    bool found = false;

    for(int i = blockedQueue.size(); i > 0; i--)
    {
        if(blockedQueue.front()->getPID() == id)
        {
            readyQueue.push(blockedQueue.front());
            found = true;
        }
        else
        {
            temp.push(blockedQueue.front());
        }
        blockedQueue.pop();
    }

    blockedQueue = temp;

    if(!found)
    {
        std::cout << "PCB not found" << std::endl;
    }
}

void cUnblock::getID(int ID)
{
    id = ID;
}
