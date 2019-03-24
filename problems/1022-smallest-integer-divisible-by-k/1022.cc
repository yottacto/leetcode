#include <iostream>
#include <algorithm>
#include "1022.hh"

int main()
{
    auto max = 0;
    for (auto k = 1; k <= 100000; k++) {
        auto n = Solution{}.smallestRepunitDivByK(k);
        max = std::max(max, n);
        std::cout << k << " " << n << " " << max << "\n";
    }
}

