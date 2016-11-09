#include "cRunAll.h"

void cRunAll::execute()
{
    std::vector<int> idList;
    std::vector<int> memList;
    std::vector<int> typeList;

    for(int i = 0; i < PCBList.size(); i++)
    {
        idList.push_back(PCBList.at(i)->getPID());
        memList.push_back(PCBList.at(i)->getMemory());
        typeList.push_back(PCBList.at(i)->getType());
    }

    Execution* e;

    std::cout << "------------------" << std::endl;
    std::cout << "Random Round Robin" << std::endl;
    std::cout << "------------------" << std::endl;
    e = new cRoundRobinRandom;
    e->execute();

    reset(idList, memList, typeList);
    std::cout << "------------------" << std::endl;
    std::cout << "   Round Robin" << std::endl;
    std::cout << "------------------" << std::endl;
    e = new cRobin;
    e->execute();

    reset(idList, memList, typeList);
    std::cout << "------------------" << std::endl;
    std::cout << "       MLFQ" << std::endl;
    std::cout << "------------------" << std::endl;
    e = new cMLFQ;
    e->execute();
}

void cRunAll::reset(std::vector<int> id, std::vector<int> mem, std::vector<int> type)
{
    cCreatePCB createTool;

    for(int i = 0; i < id.size(); i++)
    {
        createTool.getPCB(id.at(i), mem.at(i), type.at(i));
        createTool.execute();
    }
}
