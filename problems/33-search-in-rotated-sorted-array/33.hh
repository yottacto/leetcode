#pragma once
#include <vector>
#include <algorithm>

class Solution
{
public:
    auto search(std::vector<int>& a, int target)
    {
        int l = 0;
        int r = a.size() - 1;
        while (l <= r) {
            auto mid = (l + r) / 2;
            if (a[mid] == target)
                return mid;
            if ([&]() {
                return (a[mid] <= a[r])
                    ? target < a[mid] || target > a[r]
                    : target < a[mid] && target > a[r];
            }())
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l > r ? -1 : l;
    }
};

