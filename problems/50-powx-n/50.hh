#pragma once

class Solution
{
    using ll = long long;
public:

    double myPow(double x, ll n)
    {
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        auto res = 1.;
        for (; n; n /= 2, x *= x)
            if (n & 1) res *= x;
        return res;
    }
};

