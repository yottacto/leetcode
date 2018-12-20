#include <iostream>
#include "879.hh"

int main()
{

    // std::cout << Solution{}.profitableSchemes(
    //     5, 3,
    //     {2, 2},
    //     {2, 3}
    // ) << "\n";

    // std::cout << Solution{}.profitableSchemes(
    //     10, 5,
    //     {2, 3, 5},
    //     {6, 7, 8}
    // ) << "\n";

    std::cout << Solution{}.profitableSchemes(
        1,
        1,
        {2, 2, 2, 2, 2},
        {1, 2, 1, 1, 0}
    ) << "\n";

}

