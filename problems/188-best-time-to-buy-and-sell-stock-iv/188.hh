// TODO better solution O(n + k log n), split prices into consecutive ascending
// segments and transfer it into profits, and find k maximum profits
#pragma once
#include <vector>
#include <algorithm>

auto constexpr inf = 1<<30;

struct Solution
{
    int maxProfit(int k, std::vector<int>& prices)
    {
        k = std::min<int>(k, prices.size()/2);
        std::vector<int> hold(k + 1, -inf);
        std::vector<int> release(k + 1);
        for (auto p : prices)
            for (auto i = k; i >= 1; i--) {
                release[i] = std::max(release[i], hold[i] + p);
                hold[i]    = std::max(hold[i], release[i - 1] - p);
            }
        return release[k];
    }
};

