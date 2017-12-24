#pragma once
#include <algorithm>
#include <vector>

class Solution
{
public:
    int dominantIndex(std::vector<int>& nums)
    {
        int largest = -(1 << 30);
        int second = -(1 << 30);
        int pos = -1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] > largest) {
                second = largest;
                largest = nums[i];
                pos = i;
            } else {
                second = std::max(second, nums[i]);
            }
        }
        if (second * 2 > largest)
            return -1;
        return pos;
    }
};

