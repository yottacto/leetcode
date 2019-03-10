#pragma once
#include <vector>
#include <algorithm>

struct Solution
{
    int largestSumAfterKNegations(std::vector<int>& a, int k)
    {
        std::sort(a.begin(), a.end());
        for (auto& i : a)
            if (i < 0 && k) {
                i = -i;
                k--;
            }
        if (k > 0 && k & 1) {
            std::sort(a.begin(), a.end());
            a[0] = -a[0];
        }
        auto sum = 0;
        for (auto i : a)
            sum += i;
        return sum;
    }
};

