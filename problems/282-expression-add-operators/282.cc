#include <iostream>
#include "282.hh"

template <class Vec>
void print(Vec const& v)
{
    std::cout << "[";
    for (auto const& s : v)
        std::cout << s << ", ";
    std::cout << "]\n";
}

int main()
{
    // std::cout << Solution{}.eval("1*2-3+4-5-6*7+89") << "\n";
    print(Solution{}.addOperators("123", 6));
    print(Solution{}.addOperators("105", 5));
    print(Solution{}.addOperators("2147483648", -2147483648));
    // print(Solution{}.addOperators("1000000009", 9));
    // print(Solution{}.addOperators("123456789", 45));
}

