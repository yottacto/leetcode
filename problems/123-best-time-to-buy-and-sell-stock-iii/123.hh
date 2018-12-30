#pragma once
#include <vector>

auto constexpr inf = 1<<30;

struct Solution
{
    int maxProfit(std::vector<int>& prices)
    {
        auto hold1 = -inf;
        auto hold2 = -inf;
        auto release1 = 0;
        auto release2 = 0;
        for (auto i : prices) {
            release2 = std::max(release2, i + hold2);
            hold2    = std::max(hold2,    release1 - i);
            release1 = std::max(release1, i + hold1);
            hold1    = std::max(hold1,    -i);
        }
        return release2;
    }
};

