#pragma once
#include <vector>
#include <algorithm>

using ll = long long;
auto constexpr mo = 1000000007ll;

struct Solution
{
    int sumSubseqWidths(std::vector<int>& a)
    {
        int n = a.size();
        std::vector<ll> pow2(n);
        pow2[0] = 1;
        for (auto i = 1; i < n; i++)
            pow2[i] = (pow2[i - 1] * 2) % mo;

        std::sort(a.begin(), a.end());
        auto res = ll{};
        auto sum = ll{};
        for (auto i = 1; i < n; i++) {
            sum  = (2 * sum + a[i - 1]) % mo;
            res = (res + a[i] * (pow2[i] - 1) - sum) % mo;
        }
        return (res + mo) % mo;
    }
};

