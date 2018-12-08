#pragma once
#include <algorithm>
#include <vector>
#include <numeric>

struct Solution
{
    int trap(std::vector<int> const& height)
    {
        auto max = [](auto a, auto b) { return std::max(a, b); };
        auto lmax = height;
        std::partial_sum(lmax.begin(), lmax.end(), lmax.begin(), max);
        auto rmax = height;
        std::partial_sum(rmax.rbegin(), rmax.rend(), rmax.rbegin(), max);

        auto res = 0;
        for (auto i = 0u; i < height.size(); i++)
            res += std::min(lmax[i], rmax[i]) - height[i];
        return res;
    }
};

