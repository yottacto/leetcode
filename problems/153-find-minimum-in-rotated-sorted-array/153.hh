#pragma once
#include <algorithm>
#include <vector>

struct Solution
{
    int find_min(int l, int r, std::vector<int> const& a)
    {
        if (l == r) return a[l];
        auto mid = (l + r) / 2;
        auto res = std::min(a[l], a[mid + 1]);
        if (a[l] > a[mid])
            return std::min(res, find_min(l, mid, a));
        else
            return std::min(res, find_min(mid + 1, r, a));
    }

    int findMin(std::vector<int> const& a)
    {
        int n = a.size();
        if (a[0] < a[n - 1])
            return a[0];
        return find_min(0, n - 1, a);
    }
};

