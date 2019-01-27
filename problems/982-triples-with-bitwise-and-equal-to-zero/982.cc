// ml:run = time -p $bin
#include <iostream>
#include "982.hh"

int main()
{
    std::vector<int> v{
        2, 1, 3
    };
    std::cout << Solution{}.countTriplets(v) << "\n";
}

