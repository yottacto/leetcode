#include <bits/stdc++.h>

using ll = long long;

struct Solution
{
    std::vector<int> sequentialDigits(ll low, ll high)
    {
        std::vector<int> res;
        for (auto i = 2; i <= 9; i++)
            for (auto start = 1; start + i - 1 <= 9; start++) {
                auto sum = 0ll;
                for (auto j = 0; j < i; j++)
                    sum = sum * 10 + start + j;
                if (low <= sum && sum <= high)
                    res.emplace_back(sum);
            }
        return res;
    }
};

