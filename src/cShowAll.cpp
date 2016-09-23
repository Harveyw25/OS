#include "cShowAll.h"

void cShowAll::execute()
{
    std::stringstream text;
    std::vector<std::string> textList;
    for(int i = 0; i < PCBList.size(); i++)
    {
        text << "ID: " << PCBList.at(i)->getPID()
        << " Usage: " << PCBList.at(i)->getUsageTerm()
        << " Request: " << PCBList.at(i)->getRequestTerm()
        << " Waiting: " << PCBList.at(i)->getWaitingTerm()
        << " Memory: " << PCBList.at(i)->getMemory();

        textList.push_back(text.str());
        text.str(std::string());
    }
    Interface i;
    i.printToScrn(textList);

}
