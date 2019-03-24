#pragma once
#include <vector>

struct Solution
{
    int n;
    int sum{};

    auto find(std::vector<int> const& a, int p)
    {
        auto s = 0;
        for (auto i = p; i < n; i++) {
            s += a[i];
            if (s == sum)
                return i;
        }
        return n;
    }

    bool canThreePartsEqualSum(std::vector<int>& a)
    {
        n = a.size();
        for (auto i : a)
            sum += i;
        if (sum % 3) return false;
        sum /= 3;
        auto i = find(a, 0);
        if (i >= n) return false;
        auto j = find(a, i + 1);
        if (j >= n) return false;
        return true;
    }
};

