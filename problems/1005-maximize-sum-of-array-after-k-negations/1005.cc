#include <iostream>
#include "1005.hh"

int main()
{
    std::vector<int> v{4, 2, 3};
    std::cout << Solution{}.largestSumAfterKNegations(v, 1) << "\n";

    v = {3, -1, 0, 2};
    std::cout << Solution{}.largestSumAfterKNegations(v, 3) << "\n";

    v = {2,-3,-1,5,-4};
    std::cout << Solution{}.largestSumAfterKNegations(v, 2) << "\n";
}

