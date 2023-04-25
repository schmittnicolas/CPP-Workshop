#include "vice-president.hh"

#include <iostream>

void VicePresident::handle_request(int level)
{
    if (level <= 6)
    {
        std::cout << "VicePresident handles\n";
    }
    else
    {
        forward_request(level);
    }
}