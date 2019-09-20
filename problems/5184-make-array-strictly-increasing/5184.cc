#include <iostream>
#include "5184.hh"

int main()
{

    {
        std::vector<int> a1{
            1,5,3,6,7,
        };
        std::vector<int> a2{
            1,3,2,4
        };
        std::cout << Solution{}.makeArrayIncreasing(a1, a2) << "\n";
    }

}

