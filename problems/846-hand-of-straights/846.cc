#include <iostream>
#include "846.hh"

int main()
{
    {
        std::vector<int> hand{1, 2, 3, 4, 5};
        auto w = 4;
        std::cout << Solution{}.isNStraightHand(hand, w) << "\n";
    }

    {
        std::vector<int> hand{1, 2, 3, 6, 2, 3, 4, 7, 8};
        auto w = 3;
        std::cout << Solution{}.isNStraightHand(hand, w) << "\n";
    }
}

