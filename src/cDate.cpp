#include "cDate.h"

void cDate::execute()
{
    std::chrono::system_clock::time_point p = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(p);
    std::cout << std::ctime(&t) << std::endl;
}
