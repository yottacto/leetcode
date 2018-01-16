#pragma once
#include <vector>

class Solution
{
public:
    std::vector<int> findDuplicates(std::vector<int>& nums)
    {
        auto n = nums.size() + 1;
        for (auto i : nums)
            nums[(i % n) - 1] += n;

        auto p = 0;
        for (auto i = 0u; i < nums.size(); i++)
            if (nums[i] / n > 1)
                nums[p++] = i + 1;
        nums.resize(p);
        return nums;
    }
};

