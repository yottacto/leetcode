#include <iostream>
#include "33.hh"

int main()
{
    std::vector<int> v;

    v = {3, 1};
    std::cout << Solution{}.search(v, 0) << "\n";

    v = {4, 5, 6, 7, 0, 1, 2};
    std::cout << Solution{}.search(v, 4) << "\n";
    std::cout << Solution{}.search(v, 5) << "\n";
    std::cout << Solution{}.search(v, 6) << "\n";
    std::cout << Solution{}.search(v, 7) << "\n";
    std::cout << Solution{}.search(v, 0) << "\n";
    std::cout << Solution{}.search(v, 1) << "\n";
    std::cout << Solution{}.search(v, 2) << "\n";

}

