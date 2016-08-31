#include "cDirectory.h"


void cDirectory::execute()
{

    std::cout << system("dir /b C:\\Users\\Alex\\Documents\\OpSys\\OS\\Files") << std::endl;
}
