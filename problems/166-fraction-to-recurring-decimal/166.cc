#include <iostream>
#include "166.hh"

int main()
{
    std::cout << Solution{}.fractionToDecimal(1, 17) << "\n";

    std::cout << Solution{}.fractionToDecimal(49, 546) << "\n";
    std::cout << Solution{}.fractionToDecimal(-2147483648, 1) << "\n";
    std::cout << Solution{}.fractionToDecimal(-1, -2147483648) << "\n";
    std::cout << Solution{}.fractionToDecimal(1, 2147483648) << "\n";
    std::cout << Solution{}.fractionToDecimal(-1, 17) << "\n";
    std::cout << Solution{}.fractionToDecimal(0, 17) << "\n";
    std::cout << Solution{}.fractionToDecimal(50, 8) << "\n";
    std::cout << Solution{}.fractionToDecimal(-50, 8) << "\n";
}

