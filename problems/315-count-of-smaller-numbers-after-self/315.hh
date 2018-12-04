#pragma once
#include <algorithm>
#include <vector>

struct data
{
    int num;
    int id;
    int count;
};

struct Solution
{
    std::vector<data> a;
    std::vector<data> tmp;
    int n;

    void count(int l, int r)
    {
        if (l + 1 == r)
            return;
        auto mid = (l + r) / 2;
        count(l, mid);
        count(mid, r);
        auto j = mid;
        auto t = l;
        for (auto i = l; i < mid; i++) {
            while (j < r && a[j].num < a[i].num)
                tmp[t++] = a[j++];
            a[i].count += j - mid;
            tmp[t++] = a[i];
        }
        while (j < r)
            tmp[t++] = a[j++];
        std::copy(tmp.begin() + l, tmp.begin() + r, a.begin() + l);
    }

    std::vector<int> countSmaller(std::vector<int> const& nums)
    {
        n = nums.size();
        if (!n) return {};
        a.reserve(n);
        tmp.resize(n);
        for (auto i = 0; i < n; i++)
            a.emplace_back(data{nums[i], i, 0});
        count(0, n);
        std::sort(a.begin(), a.end(), [](auto const& lhs, auto const& rhs) {
            return lhs.id < rhs.id;
        });
        std::vector<int> res;
        res.reserve(n);
        for (auto const& i : a)
            res.emplace_back(i.count);
        return res;
    }
};

