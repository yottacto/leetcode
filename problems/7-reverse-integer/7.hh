#pragma once

#include <cmath>

class Solution
{
public:

    int reverse(int x)
    {
        long long ret = 0;
        for (long long a = x; a; a /= 10)
            ret = ret * 10 + (a % 10);
        if (int(ret) != ret) ret = 0;
        return ret;
    }

};

