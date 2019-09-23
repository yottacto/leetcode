#include <iostream>
#include <vector>
#include "739.hh"

template <class Vec>
void print(Vec const& v)
{
    for (auto i : v)
        std::cout << i << " ";
    std::cout << "\n";
}

int main()
{
    std::vector<int> v{73, 74, 75, 71, 69, 72, 76, 73};
    print(Solution{}.dailyTemperatures(v));
}

