// ml:std = c++14
#include <iostream>
#include "862.hh"

int main()
{
    // {
    //     std::vector<int> v{2, -1, 2};
    //     std::cout << Solution{}.shortestSubarray(v, 3) << "\n";
    // }
    // {
    //     std::vector<int> v{-28, 81, -20, 28, -29};
    //     std::cout << Solution{}.shortestSubarray(v, 89) << "\n";
    // }
    {
        std::vector<int> v{17, 85, 93, -45, -21};
        std::cout << Solution{}.shortestSubarray(v, 150) << "\n";
    }
}

