#include <iostream>
#include "327.hh"

int main()
{
    // std::cout << Solution{}.countRangeSum({-2, 5, -1}, -2, 2) << "\n";
    std::cout << Solution{}.countRangeSum(
        {-2147483647, 0, -2147483647, 2147483647},
        -564,
        3864
    ) << "\n";
}

