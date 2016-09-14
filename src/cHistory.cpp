#include "cHistory.h"

void cHistory::execute()
{
    Interface i;
    i.printToScrn(hist);
}

void cHistory::setList(std::vector <std::string> List)
{
    hist = List;
}
