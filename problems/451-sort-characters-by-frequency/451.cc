#include <iostream>
#include "451.hh"

int main()
{
    std::string s{"loveleetcode"};
    std::cout << Solution{}.frequencySort(s) << "\n";
    s = "cccaaa";
    std::cout << Solution{}.frequencySort(s) << "\n";
    s = "Aabb";
    std::cout << Solution{}.frequencySort(s) << "\n";
}

