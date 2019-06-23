#pragma once
#include <vector>
#include <algorithm>
#include <queue>

struct Solution
{
    bool carPooling(std::vector<std::vector<int>>& trips, int capacity)
    {
        std::sort(trips.begin(), trips.end(), [](auto const& a, auto const& b) {
            return a[1] < b[1];
        });

        auto current = 0;
        auto cmp = [](auto const& a, auto const& b) {
            return a[2] > b[2];
        };
        using trip_type = std::vector<int>;
        std::priority_queue<trip_type, std::vector<trip_type>, decltype(cmp)> pq(cmp);
        for (auto const& t : trips) {
            while (!pq.empty() && pq.top()[2] <= t[1]) {
                current -= pq.top()[0];
                pq.pop();
            }
            current += t[0];
            if (current > capacity)
                return false;
            pq.emplace(t);
        }
        return true;
    }
};

