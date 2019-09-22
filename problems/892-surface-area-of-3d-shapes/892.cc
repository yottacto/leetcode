#include <iostream>
#include "892.hh"

int main()
{
    std::vector<std::vector<int>> g{
        {1, 0},
        {0, 2},
    };
    std::cout << Solution{}.surfaceArea(g) << "\n";
}

