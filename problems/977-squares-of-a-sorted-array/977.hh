#pragma once
#include <algorithm>
#include <vector>

struct Solution
{
    std::vector<int> sortedSquares(std::vector<int>& a)
    {
        for (auto& i : a)
            i = i * i;
        std::sort(a.begin(), a.end());
        return a;
    }
};

