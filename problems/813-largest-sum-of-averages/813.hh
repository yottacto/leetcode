#pragma once
#include <vector>
#include <algorithm>

struct Solution
{
    auto static constexpr maxn = 107;
    double f[maxn][maxn] = {};
    int sum[maxn];

    double largestSumOfAverages(std::vector<int>& a, int k)
    {
        int n = a.size();
        for (auto i = 1; i <= n; i++)
            sum[i] = sum[i - 1] + a[i - 1];

        for (auto i = 1; i <= n; i++) {
            f[i][1] = sum[i] / (double)(i);
            for (auto j = 2; j <= std::min(k, i); j++) {
                for (auto t = i; t >= 1; t--) {
                    auto last = (sum[i] - sum[t - 1]) / (double)(i - t + 1);
                    f[i][j] = std::max(f[i][j], f[t - 1][j - 1] + last);
                }
            }
        }
        return f[n][k];
    }
};

