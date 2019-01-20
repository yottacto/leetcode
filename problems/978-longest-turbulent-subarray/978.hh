#pragma once
#include <vector>

struct Solution
{
    int f[40007][2];
    int n;

    int maxTurbulenceSize(std::vector<int>& a)
    {
        n = a.size();
        auto res = 1;
        f[n - 1][0] = 1;
        f[n - 1][1] = 1;
        for (auto i = n - 2; i >= 0; i--) {
            f[i][0] = f[i][1] = 1;
            if (a[i] > a[i + 1]) {
                f[i][0] = 1 + f[i + 1][1];
            } else if (a[i] < a[i + 1]) {
                f[i][1] = 1 + f[i + 1][0];
            }
            res = std::max(res, std::max(f[i][0], f[i][1]));
        }
        return res;
    }
};

