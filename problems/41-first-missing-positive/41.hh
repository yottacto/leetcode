#pragma once
#include <algorithm>
#include <vector>

auto inrange(int x, int l, int r)
{
    return l <= x && x <= r;
}

struct Solution
{
    int firstMissingPositive(std::vector<int>& nums)
    {
        int n = nums.size();
        for (auto i = 0; i < n; i++)
            while (inrange(nums[i], 1, n) && nums[i] != nums[nums[i] - 1])
                std::swap(nums[i], nums[nums[i] - 1]);
        for (auto i = 1; i <= n; i++)
            if (nums[i - 1] != i)
                return i;
        return n + 1;
    }
};

