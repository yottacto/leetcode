#pragma once
#include <vector>

using ll = long long;

struct Solution
{
    int minPatches(std::vector<int>& nums, int n)
    {
        ll miss = 1;
        auto count = 0;
        auto i = 0u;
        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i++];
            } else {
                miss += miss;
                count++;
            }
        }
        return count;
    }
};

