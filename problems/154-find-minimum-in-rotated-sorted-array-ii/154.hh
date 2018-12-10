#pragma once
#include <vector>

struct Solution
{
    int findMin(std::vector<int>& nums)
    {
        int n = nums.size();
        int l = 0;
        int r = n;
        while (r-l > 2) {
            if (nums[l] < nums[r-1])
                return nums[l];
            auto mid = (l + r) / 2;
            if (nums[l] == nums[r - 1] && nums[l] == nums[mid]) {
                r--;
                continue;
            }
            if (nums[mid] >= nums[l])
                l = mid + 1;
            else
                r = mid + 1;
        }
        return std::min(nums[l], nums[r - 1]);
    }
};

