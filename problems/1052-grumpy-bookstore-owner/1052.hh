#pragma once
#include <vector>

struct Solution
{
    int n;

    int maxSatisfied(std::vector<int>& customers, std::vector<int>& grumpy, int x)
    {
        n = grumpy.size();
        auto sum = 0;
        for (auto i = 0; i < n; i++)
            if (grumpy[i] == 0)
                sum += customers[i];
        std::vector<int> pre(n + 1);
        for (auto i = 1; i <= n; i++) {
            pre[i] = pre[i - 1];
            if (grumpy[i - 1] == 1)
                pre[i] += customers[i - 1];
        }
        auto res = 0;
        x = std::min(x, n);
        // std::cout << sum << "\n";
        for (auto i = x; i <= n; i++) {
            res = std::max(res, sum + pre[i] - pre[i - x]);
            // std::cout << i << " " << res << "\n";
        }
        return res;
    }
};

