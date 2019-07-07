#include <iostream>
#include "1111.hh"

template <class Vec>
void print(Vec const& v)
{
    for (auto i : v)
        std::cout << i << " ";
    std::cout << "\n";
}

int main()
{

    print(Solution{}.maxDepthAfterSplit("(()())"));

}

