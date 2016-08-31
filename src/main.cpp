#include <iostream>
#include "Interface.h"
#include "CommandList.h"
#include <string>

int main()
{
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
