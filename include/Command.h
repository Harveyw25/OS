/*  TODO

    Test
*/

#ifndef COMMAND_H
#define COMMAND_H
#include <string>

class Command
{
    public:
        Command(std::string, int);
        std::string getName();
        int getCode();
        void setName(std::string);
    protected:
    private:
        std::string name;
        int code;
};

#endif // COMMAND_H
