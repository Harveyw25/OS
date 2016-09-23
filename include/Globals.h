#ifndef GLOBALS_H
#define GLOBALS_H

#include <queue>
#include "PCB.h"
#include <vector>

extern std::queue<PCB*> readyQueue;
extern std::queue<PCB*> blockedQueue;
extern std::vector<PCB*> PCBList;
extern int currentMemory;

#endif // GLOBALS_H
