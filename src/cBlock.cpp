#include "cBlock.h"

void cBlock::execute()
{
    std::queue<PCB*> temp;
    bool found = false;

    for(int i = readyQueue.size(); i > 0; i--)
    {
        if(readyQueue.front()->getPID() == id)
        {
            blockedQueue.push(readyQueue.front());
            found = true;
        }
        else
        {
            temp.push(readyQueue.front());
        }
        readyQueue.pop();
    }

    readyQueue = temp;

    if(!found)
    {
        std::cout << "PCB not found" << std::endl;
    }
}

void cBlock::getID(int ID)
{
    id = ID;
}
