#include <iostream>
#include "710.hh"

int main()
{
    auto n = 4;
    Solution s{n, {1, 3, 0}};
    std::vector<int> count(n);
    auto tot = 10000;
    for (auto i = 0; i < tot; i++) {
        auto p = s.pick();
        count[p]++;
    }
    for (auto i = 0; i < n; i++)
        std::cout << "p[" << i << "]=" << double(count[i]) / tot << "\n";
}

