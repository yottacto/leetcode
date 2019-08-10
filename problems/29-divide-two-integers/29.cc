#include <iostream>
#include "29.hh"

int main()
{
    std::cout << Solution{}.divide(5, 2) << "\n";
    std::cout << Solution{}.divide(_max, _max) << "\n";
    std::cout << Solution{}.divide(_max, _min) << "\n";
    std::cout << Solution{}.divide(_min, _max) << "\n";
    std::cout << Solution{}.divide(_min, _min) << "\n";
}

