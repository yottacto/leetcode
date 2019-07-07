#pragma once
#include <vector>
#include <numeric>

struct Solution
{
    std::vector<int> corpFlightBookings(std::vector<std::vector<int>>& bookings, int n)
    {
        std::vector<int> sum(n);
        for (auto const& v : bookings) {
            sum[v[0] - 1] += v[2];
            if (v[1] < n)
                sum[v[1]] -= v[2];
        }
        std::partial_sum(sum.begin(), sum.end(), sum.begin());
        return sum;
    }
};

