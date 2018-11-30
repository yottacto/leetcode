#pragma once
#include <algorithm>
#include <numeric>
#include <vector>
#include <cmath>

struct Solution
{
    int minMoves2(std::vector<int>& nums)
    {
        auto n = nums.size();
        std::nth_element(nums.begin(), nums.begin() + n/2, nums.end());
        int mid = nums[n/2];
        return std::accumulate(nums.begin(), nums.end(), 0, [&](auto sum, auto i) {
            return sum + abs(i - mid);
        });
    }
};

