#include <iostream>
#include "805.hh"

int main()
{

    {
        std::vector<int> a{1, 1};
        std::cout << Solution{}.splitArraySameAverage(a) << "\n";
    }

    {
        std::vector<int> a{1, 2, 2};
        std::cout << Solution{}.splitArraySameAverage(a) << "\n";
    }

    {
        std::vector<int> a{1, 2, 3, 4, 5, 6, 7, 8};
        std::cout << Solution{}.splitArraySameAverage(a) << "\n";
    }

}

