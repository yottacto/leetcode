#pragma once
#include <cmath>

using ll = long long;

struct Solution
{
    int consecutiveNumbersSum(ll n)
    {
        ll up = std::ceil(std::sqrt(2 * n));
        auto count = 0;
        for (auto len = 1ll; len <= up; len++) {
            auto tmp = 2 * n - len * (len - 1);
            if (tmp % (2*len) != 0 && tmp)
                continue;
            count++;
        }
        return count;
    }
};

