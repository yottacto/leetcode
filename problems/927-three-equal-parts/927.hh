#pragma once
#include <algorithm>
#include <vector>

struct Solution
{
    int find(std::vector<int> const& a, int start, int ones)
    {
        int p = std::find_if(a.begin() + start, a.end(), [&, count = 0](auto x) mutable {
            return (count += (x==1)) >= ones;
        }) - a.begin();
        return p;
    }

    auto check_equal(int l1, int r1, int l2, int r2, std::vector<int> const& a)
    {
        while (l1 < r1 && a[l1] == 0)
            l1++;
        while (l2 < r2 && a[l2] == 0)
            l2++;
        if (r1 - l1 != r2 - l2)
            return false;
        for (auto i = 0; i <= r1 - l1; i++)
            if (a[l1 + i] != a[l2 + i])
                return false;
        return true;
    }

    std::vector<int> threeEqualParts(std::vector<int> const& a)
    {
        auto ones = std::count(a.begin(), a.end(), 1);
        if (ones == 0)
            return {0, 2};
        if (ones % 3)
            return {-1, -1};
        ones /= 3;
        auto last_zeros = std::find_if(
            a.rbegin(),
            a.rend(),
            [](auto x) {
                return x == 1;
            }
        ) - a.rbegin();
        auto p1 = find(a, 0, ones);
        auto p2 = find(a, p1+1, ones);
        p1 += last_zeros;
        p2 += last_zeros;
        if (check_equal(0, p1, p1 + 1, p2, a)
            && check_equal(p1 + 1, p2, p2 + 1, a.size() - 1, a))
            return {p1, p2+1};
        return {-1, -1};
    }
};

