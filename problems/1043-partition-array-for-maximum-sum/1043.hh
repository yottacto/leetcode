#pragma once
#include <vector>
#include <algorithm>

struct Solution
{
    std::vector<int> f;

    int maxSumAfterPartitioning(std::vector<int>& a, int k)
    {
        int n = a.size();
        f.resize(n + 1);
        for (auto i = 1; i <= n; i++) {
            auto max = a[i - 1];
            for (auto j = i; j >= std::max(i - k + 1, 1); j--) {
                max = std::max(max, a[j - 1]);
                f[i] = std::max(f[i], f[j - 1] + max * (i - j + 1));
            }
        }
        return f[n];
    }
};

