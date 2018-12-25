#include <iostream>
#include "719.hh"

int main()
{

    {
        std::vector<int> v{1, 4, 5, 6, 7, 8, 9, 9, 10, 10};
        std::cout << Solution{}.smallestDistancePair(v, 18) << "\n";
    }

    // {
    //     std::vector<int> v{1, 1, 1, 2, 2, 2, 3, 3, 3};
    //     std::cout << Solution{}.smallestDistancePair(v, 10) << "\n";
    // }

    // {
    //     std::vector<int> v{1, 3, 1};
    //     std::cout << Solution{}.smallestDistancePair(v, 3) << "\n";
    // }

    // {
    //     std::vector<int> v{1, 2, 3, 4, 5};
    //     std::cout << Solution{}.smallestDistancePair(v, 1) << "\n";
    // }

}

