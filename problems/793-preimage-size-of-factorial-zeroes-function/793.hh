#pragma once
#include <array>

using ll = long long;
auto constexpr maxlen = 13;

struct Solution
{
    std::array<ll, maxlen> pow5;

    void init()
    {
        pow5[0] = 1;
        for (auto i = 1; i < maxlen; i++)
            pow5[i] = pow5[i - 1] * 5;
    }

    auto sum(ll len) -> ll
    {
        auto sum = 0ll;
        auto tl = len;
        auto res = 0ll;
        for (auto i = maxlen - 1; i >= 0; i--) {
            auto count = tl/pow5[i] - sum;
            sum += count;
            res += count * (ll)(i+1);
        }
        return res;
    }

    int preimageSizeFZF(int k)
    {
        init();
        auto l = 0ll;
        auto r = 1000000000ll;
        while (l + 1 < r)  {
            auto mid = (l + r) / 2;
            if (sum(mid) > k)
                r = mid;
            else
                l = mid;
        }
        if (sum(l) >= k) r = l;
        return (sum(r) != k)
            ? 0
            : 5;
    }
};

