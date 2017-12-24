#include "a.hh"
#include <iostream>
#include <vector>


int main()
{
    std::vector<int> v;
    v = {1, 2, 3};
    std::cout << Solution{}.dominantIndex(v) << "\n";

    v = {3, 6, 1, 0};
    std::cout << Solution{}.dominantIndex(v) << "\n";

    v = {1, 2, 3, 4};
    std::cout << Solution{}.dominantIndex(v) << "\n";
}

