#pragma once
#include <algorithm>
#include <vector>

struct Solution
{
    int findLongestChain(std::vector<std::vector<int>>& pairs)
    {
        using vec = std::vector<int>;
        std::sort(pairs.begin(), pairs.end(), [](vec const& lhs, vec const& rhs) {
            return lhs[1] < rhs[1];
        });
        auto count = 0;
        auto last = -(1<<30);
        for (auto const& p : pairs)
            if (p[0] > last) {
                count++;
                last = p[1];
            }
        return count;
    }
};

