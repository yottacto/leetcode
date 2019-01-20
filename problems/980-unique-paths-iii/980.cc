// ml:opt = 0
// ml:ccf += -g
#include <iostream>
#include "980.hh"


int main()
{
    std::cerr << Solution{}.uniquePathsIII(
        {{1,0,0,0},{0,0,0,0},{0,0,2,-1}}
    ) << "\n";
}

