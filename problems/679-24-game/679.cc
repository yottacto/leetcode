#include <iostream>
#include "679.hh"

int main()
{
    // (8/(3-8/3))
    // auto res = Solution{}.dfs({8, 3, 8, 3}, {3, 1, 3});
    // for (auto i : res)
    //     std::cerr << i << ",";
    // std::cerr << "\n";
    std::cout << Solution{}.judgePoint24({3,3,8,8}) << "\n";
    // std::cout << Solution{}.judgePoint24({1, 1, 7, 7}) << "\n";
    // std::cout << Solution{}.judgePoint24({4, 1, 8, 7}) << "\n";
    // std::cout << Solution{}.judgePoint24({1, 2, 1, 2}) << "\n";
}

