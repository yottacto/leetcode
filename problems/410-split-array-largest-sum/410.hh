#pragma once
#include <algorithm>
#include <iterator>
#include <vector>

using ll = long long;

struct Solution
{
    std::vector<ll> a;
    int n;
    int m;

    auto judge(ll mid) -> bool
    {
        auto count = 1;
        auto sum = 0ll;
        for (auto i = 0; i < n; i++) {
            if (a[i] > mid)
                return false;
            if (sum + a[i] > mid) {
                count++;
                sum = 0;
            }
            sum += a[i];
        }
        return count <= m;
    }

    int splitArray(std::vector<int> const& nums, int m)
    {
        this->m = m;
        n = nums.size();
        a.reserve(n);
        std::copy(nums.begin(), nums.end(), std::back_inserter(a));
        auto l = 0ll;
        auto r = *std::max_element(a.begin(), a.end()) * n;
        while (l + 1 < r) {
            auto mid = (l + r) / 2;
            if (judge(mid))
                r = mid;
            else
                l = mid;
        }
        if (judge(l)) r = l;
        return r;
    }
};

