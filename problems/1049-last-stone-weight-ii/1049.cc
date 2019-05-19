// ml:std = c++11
#include <iostream>
#include "1049.hh"

int main()
{
    // std::vector<int> v{31, 26, 33, 21, 40};
    std::vector<int> v{1, 2};
    // std::vector<int> v{1,1,2,3,5,8,13,21,34,55,89,14,23,37,61,98};
    std::cout << Solution{}.lastStoneWeightII(v) << "\n";
}

