#pragma once
#include <string>

struct Solution
{
    int last[256][2] = {};

    int uniqueLetterString(std::string s)
    {
        int n = s.size();
        auto res = 0;
        for (auto i = 1; i <= n; i++) {
            int tid = s[i - 1];
            auto p = last[tid][0];
            auto pp = last[tid][1];
            res += (i - p) * (n - i + 1) - (p - pp) * (n - i + 1);
            last[tid][1] = last[tid][0];
            last[tid][0] = i;
        }
        return res;
    }
};

