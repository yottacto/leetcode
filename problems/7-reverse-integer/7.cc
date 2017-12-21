#include <iostream>
#include "7.hh"

int main()
{
    std::cout << Solution{}.reverse(0) << "\n";
    std::cout << Solution{}.reverse(123) << "\n";
    std::cout << Solution{}.reverse(-123) << "\n";
    std::cout << Solution{}.reverse(-1234) << "\n";
    std::cout << Solution{}.reverse(1234567899) << "\n";
    std::cout << (-123) % 10 << "\n";
}

