#ifndef PCB_H
#define PCB_H


class PCB
{
    public:
        PCB(int, int, int);
        int getPID();
        int getUsageTerm();
        int getRequestTerm();
        int getWaitingTerm();
        int getMemory();
        int getTimeEnteredBlock();
        int getType();
        int getTurnAround();
        int getResponseTime();
        int getBlockedType();
        int getTier();
        void setTimeEnteredBlock(int);
        void setType(int);
        void addUsageTerm(int);
        void addRequestTerm(int);
        void addWaitingTerm(int);
        void setTurnAround(int);
        void setResponseTime(int);
        void setBlockedType(int);
        void setTier(int);

    protected:

    private:
        int PID;
        int usageTerm;
        int requestTerm;
        int waitingTerm;
        int memory;
        int timeEnteredBlock;
        int blockedType;
        int type;
        int turnAround;
        int responseTime;
        int tier;
};

#endif
