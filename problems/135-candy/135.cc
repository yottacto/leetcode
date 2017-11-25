#include <iostream>
#include <vector>
#include "135.hh"

int main()
{
    std::vector<int> v{1, 2, 3, 4};
    std::cout << Solution{}.candy(v) << "\n";
    v = {1, 1, 1, 1};
    std::cout << Solution{}.candy(v) << "\n";
    v = {1, 2, 2};
    std::cout << Solution{}.candy(v) << "\n";
}

