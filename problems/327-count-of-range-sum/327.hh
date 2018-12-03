#pragma once
#include <vector>
#include <numeric>

using ll = long long;

struct Solution
{
    ll lower;
    ll upper;

    std::vector<ll> a;
    std::vector<ll> tmp;

    ll count(int l, int r)
    {
        if (l == r)
            return 0;
        auto mid = (l + r) / 2;
        auto res = count(l, mid) + count(mid + 1, r);
        auto j = mid + 1;
        auto k = mid + 1;
        auto tr = mid + 1;
        auto t = l;
        for (auto i = l; i <= mid; i++) {
            while (j <= r && a[j] - a[i] < lower)
                j++;
            while (k <= r && a[k] - a[i] <= upper)
                k++;
            res += k - j;
            while (tr <= r && a[tr] <= a[i])
                tmp[t++] = a[tr++];
            tmp[t++] = a[i];
        }
        std::copy(tmp.begin() + l, tmp.begin() + r + 1, a.begin() + l);
        return res;
    }

    int countRangeSum(std::vector<int> const& nums, ll lower, ll upper)
    {
        this->lower = lower;
        this->upper = upper;
        a.reserve(nums.size() + 1);
        a.emplace_back(0);
        std::copy(nums.begin(), nums.end(), std::back_inserter(a));
        std::partial_sum(a.begin(), a.end(), a.begin());
        tmp = a;
        return count(0, a.size() - 1);
    }
};

