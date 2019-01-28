#pragma once
#include <vector>
#include <string>

struct Solution
{
    int n;
    int l;

    int minDeletionSize(std::vector<std::string>& a)
    {
        n = a.size();
        l = a[0].size();
        std::vector<int> f(l + 1);
        auto res = l;
        for (auto i = 0; i < l; i++) {
            f[i + 1] = i;
            for (auto j = i - 1; j >= 0; j--) {
                auto all = true;
                for (auto k = 0; k < n; k++)
                    if (a[k][i] < a[k][j]) {
                        all = false;
                        break;
                    }
                if (all)
                    f[i + 1] = std::min(f[i + 1], f[j + 1] + i - j - 1);
            }
            res = std::min(res, f[i + 1] + l - i - 1);
        }
        return res;
    }
};

