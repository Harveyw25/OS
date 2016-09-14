/*  TODO

    Implement
    Test
*/

#ifndef CHISTORY_H
#define CHISTORY_H

#include "Interface.h"
#include "Execution.h"
#include <iostream>
#include <vector>
#include <string>


class cHistory : public Execution
{
    public:
        virtual void execute();
        void setList(std::vector <std::string>);
    protected:
    private:
        std::vector <std::string> hist;
};

#endif // CHISTORY_H
