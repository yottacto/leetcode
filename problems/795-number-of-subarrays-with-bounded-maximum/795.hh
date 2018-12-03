#pragma once
#include <vector>
#include <deque>

using ll = long long;

struct Solution
{
    auto inrange(int x, int l, int r)
    {
        return l <= x && x <= r;
    }

    ll numSubarrayBoundedMax(std::vector<int> const& a, int l, int r)
    {
        auto last = -1;
        int n = a.size();
        std::deque<int> dq;
        auto res = 0ll;
        for (auto i = 0; i < n; i++) {
            while (!dq.empty() && a[i] >= a[dq.back()])
                dq.pop_back();
            dq.push_back(i);
            while (!dq.empty() && !inrange(a[dq.front()], l, r)) {
                if (a[dq.front()] > r)
                    last = dq.front();
                dq.pop_front();
            }
            while (!dq.empty() && !inrange(a[dq.back()], l, r))
                dq.pop_back();
            auto right = last;
            if (!dq.empty())
                right = dq.back();
            res += right - last;
        }
        return res;
    }
};

