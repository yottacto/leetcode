#pragma once
#include <vector>
#include <set>

using ll = long long;

auto constexpr inf = (1ll)<<50;

struct median
{
    median()
    {
        l.emplace(-inf);
        r.emplace(+inf);
    }

    void l_to_r()
    {
        auto x = *l.rbegin();
        r.emplace(x);
        l.erase(l.find(x));
    }

    void r_to_l()
    {
        auto x = *r.begin();
        l.emplace(x);
        r.erase(r.find(x));
    }

    void insert(ll x)
    {
        if (x < *l.rbegin()) {
            l.emplace(x);
            if (l.size() > r.size() + 1)
                l_to_r();
        } else if (x > *r.begin()) {
            r.emplace(x);
            if (r.size() > l.size())
                r_to_l();
        } else {
            if (l.size() == r.size())
                l.emplace(x);
            else
                r.emplace(x);
        }
    }

    void erase(ll x)
    {
        if (l.count(x) && r.count(x)) {
            if (l.size() == r.size())
                r.erase(r.find(x));
            else
                l.erase(l.find(x));
        } else if (l.count(x)) {
            l.erase(l.find(x));
            if (l.size() < r.size())
                r_to_l();
        } else {
            r.erase(r.find(x));
            if (l.size() > r.size() + 1)
                l_to_r();
        }
    }

    int size() const
    {
        return l.size() + r.size() - 2;
    }

    double get_median() const
    {
        if (size() & 1)
            return *l.rbegin();
        return (*l.rbegin() + *r.begin()) / 2.;
    }

    std::multiset<ll> l;
    std::multiset<ll> r;
};

struct Solution
{
    auto medianSlidingWindow(std::vector<int>& nums, int k) -> std::vector<double>
    {
        if (nums.empty()) return {};
        median m;
        for (auto i = 0; i < k - 1; i++)
            m.insert(nums[i]);
        std::vector<double> res;
        int n = nums.size();
        for (auto i = k - 1; i < n; i++) {
            m.insert(nums[i]);
            res.emplace_back(m.get_median());
            m.erase(nums[i - k + 1]);
        }
        return res;
    }
};

