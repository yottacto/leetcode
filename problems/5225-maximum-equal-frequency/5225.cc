#include <iostream>
#include "5225.hh"

int main()
{

    {
        std::vector<int> v{10,2,8,9,3,8,1,5,2,3,7,6};
        std::cout << Solution{}.maxEqualFreq(v) << "\n";
    }

    {
        std::vector<int> v{2,2,1,1,5,3,3,5};
        std::cout << Solution{}.maxEqualFreq(v) << "\n";
    }

    {
        std::vector<int> v{1,1,1,2,2,2,3,3,3,4,4,4,5};
        std::cout << Solution{}.maxEqualFreq(v) << "\n";
    }

    {
        std::vector<int> v{1,1,1,2,2,2};
        std::cout << Solution{}.maxEqualFreq(v) << "\n";
    }

    {
        std::vector<int> v{10,2,8,9,3,8,1,5,2,3,7,6};
        std::cout << Solution{}.maxEqualFreq(v) << "\n";
    }


}

