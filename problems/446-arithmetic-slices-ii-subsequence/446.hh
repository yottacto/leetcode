#pragma once
#include <vector>
#include <unordered_map>

using ll = long long;

class Solution
{
public:
    int numberOfArithmeticSlices(std::vector<int> const& a)
    {
        int n = a.size();
        auto ret = 0;
        std::vector<std::unordered_map<ll, int>> f(n);
        for (auto i = 1; i < n; i++) {
            for (auto j = i - 1; j >= 0; j--) {
                auto d = static_cast<ll>(a[i]) - a[j];
                if (f[j].count(d))
                    f[i][d] += f[j][d] + 1;
                else
                    f[i][d] += 1;
                ret--;
            }
            for (auto j : f[i])
                ret += j.second;
        }
        return ret;
    }
};

