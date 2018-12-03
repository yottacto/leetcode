// more concise solution
#pragma once
#include <vector>
#include <deque>

struct Solution
{
    int numSubarrayBoundedMax(std::vector<int> const& a, int l, int r)
    {
        auto left = -1;
        auto right = -1;
        int n = a.size();
        auto res = 0;
        for (auto i = 0; i < n; i++) {
            if (a[i] > r) left = i;
            if (a[i] >= l) right = i;
            res += right - left;
        }
        return res;
    }
};

