#pragma once
#include <vector>

struct Solution
{
    int numSubarraysWithSum(std::vector<int>& a, int s)
    {
        int n = a.size();
        std::vector<int> count(n + 1);
        auto sum = 0;
        auto ans = 0;
        count[0] = 1;
        for (auto i = 1; i <= n; i++) {
            sum += a[i-1];
            if (sum >= s)
                ans += count[sum - s];
            count[sum]++;
        }
        return ans;
    }
};

