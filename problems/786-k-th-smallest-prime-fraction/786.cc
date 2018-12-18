#include <iostream>
#include "786.hh"

int main()
{

    {
        auto res = Solution{}.kthSmallestPrimeFraction(
            {1, 2, 3, 5},
            3
            );
        std::cout << res[0] << " " << res[1] << "\n";
    }

}

