#include <bits/stdc++.h>

auto constexpr inf = 1<<30;

struct Solution
{
    int minFallingPathSum(std::vector<std::vector<int>>& a)
    {
        int n = a.size();
        std::vector<std::vector<int>> f(n, std::vector<int>(n, inf));
        for (auto i = 0; i < n; i++)
            f[0][i] = a[0][i];
        for (auto i = 1; i < n; i++)
            for (auto j = 0; j < n; j++) {
                for (auto k = 0; k < n; k++) {
                    if (k == j)
                        continue;
                    f[i][j] = std::min(f[i][j], f[i - 1][k] + a[i][j]);
                }
            }
        auto res = inf;
        for (auto i = 0; i < n; i++)
            res = std::min(res, f[n - 1][i]);
        return res;
    }
};

