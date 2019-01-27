#pragma once
#include <vector>
#include <unordered_map>

struct Solution
{
    int n;
    std::unordered_map<int, int> count;

    int countTriplets(std::vector<int>& a)
    {
        n = a.size();
        auto ans = 0;
        for (auto i = 0; i < (1<<16); i++)
            for (auto j = 0; j < n; j++)
                if (!(a[j] & i))
                    count[i]++;

        for (auto i = 0; i < n; i++)
            for (auto j = 0; j < n; j++) {
                auto s = a[i] & a[j];
                ans += count[s];
            }
        return ans;
    }
};

