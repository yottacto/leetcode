#include <iostream>
#include "446.hh"

int main()
{
    std::cout
        << Solution{}.numberOfArithmeticSlices({2, 4, 6, 8, 10}) << "\n"
        << Solution{}.numberOfArithmeticSlices({1, 1, 1, 1, 1}) << "\n"
        << Solution{}.numberOfArithmeticSlices({0, 2000000000, -294967296}) << "\n"
        << Solution{}.numberOfArithmeticSlices({2, 2, 3, 4}) << "\n";
}

