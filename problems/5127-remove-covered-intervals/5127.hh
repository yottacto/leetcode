#include <bits/stdc++.h>

struct Solution
{
    int removeCoveredIntervals(std::vector<std::vector<int>>& ints)
    {
        int n = ints.size();
        std::sort(ints.begin(), ints.end(), [](auto const& a, auto const& b) {
            return a[0] < b[0]
                || (a[0] == b[0] && a[1] > b[1]);
        });
        auto max = -1;
        auto res = n;
        for (auto i = 0; i < n; i++) {
            if (max >= ints[i][1])
                res--;
            max = std::max(max, ints[i][1]);
        }
        return res;
    }
};

