#include <iostream>
#include "227.hh"

int main()
{
    std::cout << Solution{}.calculate("2147483647") << "\n";
    std::cout << Solution{}.calculate("3+2*2") << "\n";
    std::cout << Solution{}.calculate("10/1/2/3/4") << "\n";
}

