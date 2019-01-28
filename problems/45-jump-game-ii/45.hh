#pragma once
#include <algorithm>
#include <vector>

struct Solution
{
    int jump(std::vector<int> const& nums)
    {
        int n = nums.size();
        if (n == 1) return 0;
        auto end = nums[0];
        if (end >= n - 1)
            return 1;
        auto jump = 0;
        auto max = 0;
        for (auto i = 1; i < n; i++) {
            if (i > end) {
                jump++;
                end = max;
                max = i + nums[i];
                if (end >= n - 1)
                    return jump + 1;
            } else {
                max = std::max(max, i + nums[i]);
            }
        }
        return jump + 1;
    }
};

