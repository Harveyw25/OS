#ifndef PCB_H
#define PCB_H


class PCB
{
    public:
        PCB(int, int);
        int getPID();
        int getUsageTerm();
        int getRequestTerm();
        int getWaitingTerm();
        int getMemory();
        int getTimeEnteredBlock();
        int getType();
        void setTimeEnteredBlock(int);
        void setType(int);
        void addUsageTerm(int);
        void addRequestTerm(int);
        void addWaitingTerm(int);

    protected:

    private:
        int PID;
        int usageTerm;
        int requestTerm;
        int waitingTerm;
        int memory;
        int timeEnteredBlock;
        int type;
};

#endif
