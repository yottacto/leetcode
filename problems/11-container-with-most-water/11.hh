#pragma once
#include <vector>
#include <algorithm>

struct Solution
{
    int maxArea(std::vector<int> const& height)
    {
        int n = height.size();
        auto l = 0;
        auto r = n - 1;
        auto ans = 0;
        while (l < r) {
            ans = std::max(ans, (r - l) * std::min(height[l], height[r]));
            if (height[l] > height[r])
                r--;
            else
                l++;
        }
        return ans;
    }
};

