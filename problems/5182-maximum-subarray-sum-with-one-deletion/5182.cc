#include <iostream>
#include "5182.hh"

int main()
{

    {
        std::vector<int> v{
            1, -2, 0, 3
        };
        std::cout << Solution{}.maximumSum(v) << "\n";
    }

    {
        std::vector<int> v{
            1,-2,-2,3
        };
        std::cout << Solution{}.maximumSum(v) << "\n";
    }

}

