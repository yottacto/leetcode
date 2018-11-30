#pragma once
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>

struct Solution
{
    bool find132pattern(std::vector<int>& nums)
    {
        if (nums.size() < 3)
            return false;
        auto min = nums;
        std::partial_sum(min.begin(), min.end(), min.begin(), [](auto a, auto b) {
            return std::min(a, b);
        });
        int n = nums.size();
        for (auto i = n - 1, k = n; i >= 0; i--) {
            if (nums[i] <= min[i])
                continue;
            while (k < n && nums[k] <= min[i])
                k++;
            if (k < n && nums[k] < nums[i])
                return true;
            nums[--k] = nums[i];
        }
        return false;
    }
};

