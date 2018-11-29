#include <iostream>
#include "881.hh"

int main()
{
    {
        std::vector<int> v{1, 2};
        std::cout << Solution{}.numRescueBoats(v, 3) << "\n";
    }

    {
        std::vector<int> v{3, 2, 2, 1};
        std::cout << Solution{}.numRescueBoats(v, 3) << "\n";
    }

    {
        std::vector<int> v{3, 5, 3, 4};
        std::cout << Solution{}.numRescueBoats(v, 5) << "\n";
    }
}

