#pragma once
#include <vector>
#include <algorithm>

struct Solution
{
    std::vector<int> addToArrayForm(std::vector<int>& a, int k)
    {
        std::reverse(a.begin(), a.end());
        auto i = 0u;
        a[0] += k;
        while (i < a.size() && a[i] >= 10) {
            if (i == a.size() - 1)
                a.emplace_back(0);
            a[i + 1] += a[i] / 10;
            a[i] %= 10;
            i++;
        }
        std::reverse(a.begin(), a.end());
        return a;
    }
};

