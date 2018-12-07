#include <iostream>
#include "689.hh"

template <class Vec>
void print(Vec const& v)
{
    std::cout << "[";
    for (auto i : v)
        std::cout << i << ", ";
    std::cout << "]\n";
}

int main()
{
    print(Solution{}.maxSumOfThreeSubarrays({1, 2, 1, 2, 6, 7, 5, 1}, 2));
    print(Solution{}.maxSumOfThreeSubarrays({6,3,2,6,8,8,1,2,3,45,7,8,1,1,2,3,4}, 2));
    print(Solution{}.maxSumOfThreeSubarrays({6,3,2,6,8,8,1,2,3,45,7,8,1,1,2,3,4}, 1));
}

