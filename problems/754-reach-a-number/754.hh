#pragma once

class Solution
{
    template <class T>
    T abs(T x) { return x < 0 ? -x : x; }

public:

    int reachNumber(long long target)
    {
        target = abs(target);
        long long sum = 0;
        for (int i = 0; ; i++) {
            sum += i;
            if (sum < target || ((sum - target) & 1))
                continue;
            return i;
        }
    }
};

