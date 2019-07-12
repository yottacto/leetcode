#pragma once
#include <vector>
#include <algorithm>
#include <numeric>
#include <deque>

struct Solution
{
    int shortestSubarray(std::vector<int>& a, int k)
    {
        int n = a.size();
        auto res = n + 1;
        std::vector<int> sum(n + 1);
        std::partial_sum(a.begin(), a.end(), sum.begin() + 1);
        std::deque<int> dq;
        dq.emplace_back(0);
        for (auto i = 1; i <= n; i++) {
            while (!dq.empty() && sum[i] - sum[dq.front()] >= k) {
                res = std::min(res, i - dq[0]);
                dq.pop_front();
            }
            while (!dq.empty() && sum[i] <= sum[dq.back()])
                dq.pop_back();
            dq.emplace_back(i);
        }
        if (res == n + 1)
            res = -1;
        return res;
    }
};

