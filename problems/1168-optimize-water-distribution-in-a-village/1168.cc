#include <iostream>
#include "1168.hh"

int main()
{
    std::vector<int> wells{1,2,2};
    std::vector<std::vector<int>> pipes{
        {1, 2, 1},
        {2, 3, 1},
    };
    std::cout << Solution{}.minCostToSupplyWater(3, wells, pipes) << "\n";
}

