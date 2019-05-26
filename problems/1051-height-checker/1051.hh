#pragma once
#include <vector>
#include <algorithm>

struct Solution
{
    int heightChecker(std::vector<int>& h)
    {
        int n = h.size();
        auto o = h;
        std::sort(h.begin(), h.end());
        auto count = 0;
        for (auto i = 0; i < n; i++)
            if (h[i] != o[i])
                count++;
        return count;
    }
};

