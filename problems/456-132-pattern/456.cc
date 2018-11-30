#include <iostream>
#include "456.hh"

int main()
{
    std::vector v{1, -4, 2, -1, 3, -3, -4, 0, -3, -1};
    std::cout << Solution{}.find132pattern(v) << "\n";
}

