#pragma once
#include <algorithm>
#include <vector>

struct Solution
{
    int find(std::vector<int>& days, int d)
    {
        return std::upper_bound(days.begin(), days.end(), d) - days.begin();
    }

    int mincostTickets(std::vector<int>& days, std::vector<int>& costs)
    {
        int n = days.size();
        std::vector<int> f(n + 1);
        for (auto i = 0; i < n; i++) {
            f[i + 1] = f[i] + costs[0];
            f[i + 1] = std::min(f[i + 1], f[find(days, days[i] - 7)] + costs[1]);
            f[i + 1] = std::min(f[i + 1], f[find(days, days[i] - 30)] + costs[2]);
        }
        return f[n];
    }
};

