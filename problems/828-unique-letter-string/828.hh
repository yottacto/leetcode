#pragma once
#include <string>

struct Solution
{
    int last[30] = {};
    int prev[10007];
    int n;

    int id(std::string s, int i)
    {
        return s[i-1] - 'A';
    }

    int uniqueLetterString(std::string s)
    {
        n = s.size();
        for (auto i = 1; i <= n; i++) {
            prev[i] = last[id(s, i)];
            last[id(s, i)] = i;
        }
        auto res = 0;
        for (auto i = 1; i <= n; i++) {
            auto p = prev[i];
            auto pp = prev[prev[i]];
            res += -1 * (p - pp) * (n - i + 1);
            res += +1 * (i - p) * (n - i + 1);
        }
        return res;
    }
};

