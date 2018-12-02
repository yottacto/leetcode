// NOTE: the O(1) space solution is that set start=n-1, end=0, and maintain sum like
// below, every time if sum is >= 0, extend end, every time sum is < 0,
// start--, keep doing this when we handled all station and the start is our
// solution if there is one.
#pragma once
#include <algorithm>
#include <iterator>
#include <numeric>
#include <vector>
#include <deque>

struct Solution
{
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost)
    {
        int n = gas.size();
        gas.reserve(2 * n);
        std::copy_n(gas.begin(), n, std::back_inserter(gas));
        cost.reserve(2 * n);
        std::copy_n(cost.begin(), n, std::back_inserter(cost));
        auto sum = gas;
        for (auto i = 0; i < 2 * n; i++)
            sum[i] -= cost[i];
        std::partial_sum(sum.begin(), sum.end(), sum.begin());
        std::deque<int> dq;
        for (auto i = 0; i < n - 1; i++) {
            while (!dq.empty() && sum[dq.back()] > sum[i])
                dq.pop_back();
            dq.push_back(i);
        }
        for (auto i = 0; i < n; i++) {
            while (!dq.empty() && dq.front() < i)
                dq.pop_front();
            while (!dq.empty() && sum[dq.back()] > sum[i + n - 1])
                dq.pop_back();
            dq.push_back(i + n - 1);
            auto min = sum[dq.front()];
            auto prev = i == 0 ? 0 : sum[i - 1];
            if (min - prev >= 0)
                return i;
        }
        return -1;
    }
};

