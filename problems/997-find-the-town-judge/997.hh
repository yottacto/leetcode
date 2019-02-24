#pragma once
#include <vector>

struct Solution
{
    std::vector<int> trusted;
    std::vector<int> trust_some;

    int findJudge(int n, std::vector<std::vector<int>>& trust)
    {
        trusted.resize(n + 1);
        trust_some.resize(n + 1);
        for (auto const& v : trust) {
            trust_some[v[0]]++;
            trusted[v[1]]++;
        }
        auto count = 0;
        int pos{-1};
        for (auto i = 1; i <= n; i++)
            if (trusted[i] == n - 1 && !trust_some[i]) {
                count++;
                pos = i;
            }
        if (count == 1)
            return pos;
        return -1;
    }
};

