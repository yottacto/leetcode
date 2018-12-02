// ml:opt = 0
// ml:ccf += -g
// ml:std = c++11
#include <iostream>
#include "889.hh"

int main()
{
    std::cout << Solution{}.constructFromPrePost(
        {4, 1, 7, 21, 9, 18, 2, 13, 11, 22, 3, 5, 12, 10, 17, 16, 20, 14, 8, 15, 19, 6 },
        {3, 22, 11, 17, 20, 16, 10, 12, 5, 13, 2, 18, 14, 9, 21, 6, 19, 15, 8, 7, 1, 4}
    ) << "\n";
}

