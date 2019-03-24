#pragma once

struct Solution
{
    int smallestRepunitDivByK(int k)
    {
        auto s = 0;
        for (auto l = 1; l <= 1000000; l++) {
            s = s * 10 + 1;
            s %= k;
            if (!s)
                return l;
        }
        return -1;
    }
};

