#include <iostream>
#include "50.hh"

int main()
{
    std::cout << Solution{}.myPow(2.1, 3) << "\n";
    std::cout << Solution{}.myPow(0, 3) << "\n";
    std::cout << Solution{}.myPow(0, -3) << "\n";
    std::cout << Solution{}.myPow(1., -3) << "\n";
    std::cout << Solution{}.myPow(1., -2147483648) << "\n";
}

