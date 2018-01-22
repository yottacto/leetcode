#pragma once
#include <vector>
#include <algorithm>

class Solution
{
public:
    int search(std::vector<int>& a, int target)
    {
        int l = 0;
        int r = a.size() - 1;
        while (l < r) {
            auto mid = (l + r) / 2;
            if (a[mid] == target)
                return mid;
            if (a[mid] <= a[r]) {
                if (target > a[mid]) {
                    if (target > a[r]) r = mid - 1;
                    else l = mid + 1;
                }
                if (target < a[mid]) r = mid - 1;
            } else{
                if (target > a[mid]) l = mid + 1;
                if (target < a[mid]) {
                    if (target <= a[r]) l = mid + 1;
                    else r = mid - 1;
                }
            }
        }
        if (l > r || a[l] != target) return -1;
        return l;
    }
};

