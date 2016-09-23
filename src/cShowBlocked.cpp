#include "cShowBlocked.h"

void cShowBlocked::execute()
{
    std::stringstream text;
    std::vector<std::string> textList;
    std::queue<PCB*> tempQueue = blockedQueue;

    for(int i = 0; i < blockedQueue.size(); i++)
    {
        text << "ID: " << tempQueue.front()->getPID()
        << " Usage: " << tempQueue.front()->getUsageTerm()
        << " Request: " << tempQueue.front()->getRequestTerm()
        << " Waiting: " << tempQueue.front()->getWaitingTerm()
        << " Memory: " << tempQueue.front()->getMemory();

        tempQueue.pop();
        textList.push_back(text.str());
        text.str(std::string());
    }
    Interface i;
    i.printToScrn(textList);
}
