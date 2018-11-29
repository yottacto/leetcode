#pragma once
#include <algorithm>
#include <vector>

struct Solution
{
    int f[6000] = {};

    int change(int amount, std::vector<int>& coins)
    {
        std::sort(coins.begin(), coins.end());
        coins.erase(std::unique(coins.begin(), coins.end()), coins.end());

        f[0] = 1;
        for (auto c : coins) {
            for (auto i = c; i <= amount; i++)
                f[i] += f[i - c];
        }
        return f[amount];
    }
};

