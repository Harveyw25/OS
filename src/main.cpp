#include <iostream>
#include "Interface.h"
#include "CommandList.h"
#include "Globals.h"
#include <string>
#include <stdio.h>
#include <fstream>


int main()
{

    std::string fileName = "Memory.txt";
    std::ifstream inData;
    inData.open(fileName.c_str());

    if(inData.is_open())
    {
        inData >> currentMemory;
    }
    else
    {
        std::cout << "Memory.txt is missing" << std::endl;
    }
    inData.close();

    CommandList L;
    int cont = 1;

    std::cout << "Welcome to (insert clever name here)OS!" << std::endl;
    std::cout << "Type help if you need assistance!" << std::endl;

    while(cont)
    {
        std::string input = "";
        std::cin >> input;
        cont = L.addCommand(input);
    }
    return 0;
}
