#pragma once
#include <algorithm>
#include <vector>

struct Solution
{
    int maxProduct(std::vector<int>& nums)
    {
        auto res = nums[0];
        int n = nums.size();
        for (auto i = 1, min = nums[0], max = nums[0]; i < n; i++) {
            auto tmax = std::max(
                std::max(min * nums[i], max * nums[i]),
                nums[i]
            );

            auto tmin = std::min(
                std::min(min * nums[i], max * nums[i]),
                nums[i]
            );
            max = tmax;
            min = tmin;
            res = std::max(res, max);
        }
        return res;
    }
};

