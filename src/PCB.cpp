#include "PCB.h"

PCB::PCB(int id, int mem)
{
    PID = id;
    usageTerm = 0;
    requestTerm = 0;
    waitingTerm = 0;
    memory = mem;
}

int PCB::getPID()
{
    return PID;
}

int PCB::getUsageTerm()
{
    return usageTerm;
}

int PCB::getRequestTerm()
{
    return requestTerm;
}

int PCB::getWaitingTerm()
{
    return waitingTerm;
}

int PCB::getMemory()
{
    return memory;
}

int PCB::getTimeEnteredBlock()
{
    return timeEnteredBlock;
}

int PCB::getType()
{
    return type;
}

void PCB::setTimeEnteredBlock(int num)
{
    timeEnteredBlock = num;
}

void PCB::setType(int num)
{
    type = num;
}

void PCB::addUsageTerm(int num)
{
    usageTerm += num;
}

void PCB::addRequestTerm(int num)
{
    requestTerm += num;
}

void PCB::addWaitingTerm(int num)
{
    waitingTerm += num;
}
