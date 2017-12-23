#include <iostream>
#include <vector>
#include "66.hh"

template <class T>
void print(T const& v)
{
    for (auto i : v) std::cout << i;
    std::cout << "\n";
}

int main()
{
    std::vector<int> v;
    v = {8, 9, 9, 9};
    print(Solution{}.plusOne(v));
    v = {1, 2, 3};
    print(Solution{}.plusOne(v));
    v = {9};
    print(Solution{}.plusOne(v));
}

