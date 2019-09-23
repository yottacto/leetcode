#include <iostream>
#include "313.hh"

int main()
{
    std::vector<int> primes{2, 7, 13, 19};
    std::cout << Solution{}.nthSuperUglyNumber(12, primes) << "\n";
}

