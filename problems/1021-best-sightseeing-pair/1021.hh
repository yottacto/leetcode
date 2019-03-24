#pragma once
#include <vector>

struct Solution
{
    int maxScoreSightseeingPair(std::vector<int>& a)
    {
        int n = a.size();
        auto p = a;
        for (auto i = 0; i < n; i++)
            p[i] -= i;
        std::vector<int> max(n);
        std::vector<int> max_p(n);
        max[n - 1] = p[n - 1];
        max_p[n - 1] = n - 1;
        for (auto i = n - 2; i >= 0; i--) {
            max[i] = max[i + 1];
            max_p[i] = max_p[i + 1];
            if (p[i + 1] > max[i]) {
                max[i] = p[i + 1];
                max_p[i] = i + 1;
            }
        }
        auto res = -(1<<30);
        for (auto i = 0; i < n - 1; i++) {
            auto j = max_p[i];
            res = std::max(res, a[i] + a[j] + i - j);
        }
        return res;
    }
};

