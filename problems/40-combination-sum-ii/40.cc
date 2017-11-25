#include <iostream>
#include <vector>
#include "40.hh"

template <class V>
void print(V const& v)
{
    std::cout << v.size() << "\n";
    for (auto vi : v) {
        std::cout << "[";
        for (auto i : vi) std::cout << i << ", ";
        std::cout << "]\n";
    }
}

int main()
{
    std::vector<int> v{10, 1, 2, 7, 6, 1, 5};
    auto target = 8;
    print(Solution{}.combinationSum2(v, target));

    v = {1, 1, 1, 1, 2, 2, 3, 3, 4};
    target = 4;
    print(Solution{}.combinationSum2(v, target));
}

