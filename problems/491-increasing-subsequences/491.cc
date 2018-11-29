#include <iostream>
#include "491.hh"

template <class VecVec>
void print(VecVec const& vv)
{
    std::cout << "[";
    for (auto const& v : vv) {
        std::cout << "[";
        for (auto i : v)
            std::cout << i << ", ";
        std::cout << "], ";
    }
    std::cout << "]\n";
}

int main()
{
    {
        std::vector<int> v{4, 6, 7, 7};
        print(Solution{}.findSubsequences(v));
    }

}

