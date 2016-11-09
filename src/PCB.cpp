#include "PCB.h"

PCB::PCB(int id, int mem, int t)
{
    type = t;
    PID = id;
    usageTerm = 0;
    requestTerm = 0;
    waitingTerm = 0;
    memory = mem;
    tier = 0;
    turnAround = 0;
    responseTime = 0;
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

int PCB::getTurnAround()
{
    return turnAround;
}

int PCB::getResponseTime()
{
    return responseTime;
}

int PCB::getBlockedType()
{
    return blockedType;
}

int PCB::getTier()
{
    return tier;
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

void PCB::setTurnAround(int num)
{
    turnAround = num;
}

void PCB::setResponseTime(int num)
{
    responseTime = num;
}

void PCB::setBlockedType(int num)
{
    blockedType = num;
}

void PCB::setTier(int num)
{
    tier = num;
}
