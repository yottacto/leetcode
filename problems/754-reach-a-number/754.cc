#include <iostream>
#include "754.hh"

int main()
{
    for (int i = 0; i < 20; i++)
        std::cout << "dis[" << i << "] = " << Solution{}.reachNumber(i) << "\n";
}

