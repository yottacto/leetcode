#include <iostream>
#include "363.hh"

int main()
{

    {
        std::vector<std::vector<int>> mat{
            {1, 0, 1},
            {0, -2, 3},
        };
        std::cout << Solution{}.maxSumSubmatrix(mat, 2) << "\n";
    }

    {
        std::vector<std::vector<int>> mat{
            {5,  -4, -3, 4},
            {-3, -4, 4,  5},
            {5,  1,  5,  -4}
        };
        std::cout << Solution{}.maxSumSubmatrix(mat, 10) << "\n";
    }

}

