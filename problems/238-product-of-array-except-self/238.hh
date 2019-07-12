#pragma once
#include <vector>

struct Solution
{
    std::vector<int> productExceptSelf(std::vector<int>& nums)
    {
        int n = nums.size();
        std::vector<int> res(n, 1);
        for (auto i = n - 2; i >= 0; i--)
            res[i] = res[i + 1] * nums[i + 1];
        auto left = 1;
        for (auto i = 1; i < n; i++) {
            left *= nums[i - 1];
            res[i] *= left;
        }
        return res;
    }
};

