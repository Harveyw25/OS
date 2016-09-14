#include "cBatch.h"

void cBatch::execute()
{
    CommandList List;
    std::string fileName = "";
    std::cout << "Enter a file name" << std::endl;
    std::cin >> fileName;
    std::ifstream inData;
    inData.open(fileName.c_str());
    std::string line = "";

    while(inData.is_open())
    {
        while(getline(inData, line))
        {
            List.addCommand(line);
        }
    }
    inData.close();
}
