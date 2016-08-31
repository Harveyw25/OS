#include "Interface.h"


Interface::Interface()
{

}

void Interface::printToScrn(std::vector <std::string> textToPrnt)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;


    int line = 0;

    while(line < textToPrnt.size())
    {
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        for(int i = 0; (i < csbi.srWindow.Bottom - csbi.srWindow.Top + 2) && line < textToPrnt.size(); i++)
        {
            std::cout << textToPrnt.at(line) << std::endl;
            line++;
        }
        if(line+1 < textToPrnt.size())
        {
            std::cout << "Press enter to continue";
            std::cin.get();
        }

    }

}
