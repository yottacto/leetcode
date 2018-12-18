#pragma once
#include <algorithm>
#include <vector>
#include <queue>

struct data
{
    data(int p, int c) : p(p), c(c) {}
    int p;
    int c;
};

auto operator<(data const & lhs, data const& rhs)
{
    return lhs.p < rhs.p;
}

struct Solution
{
    int findMaximizedCapital(
        int k,
        int w,
        std::vector<int>& profits,
        std::vector<int>& capital
    )
    {
        int n = profits.size();
        std::vector<data> da;
        da.reserve(n);
        for (auto i = 0; i < n; i++)
            da.emplace_back(profits[i], capital[i]);
        std::sort(da.begin(), da.end(), [](auto const& a, auto const& b) {
            return a.c < b.c;
        });

        std::priority_queue<data> pq;
        auto it = da.begin();
        while (k--) {
            for (; it != da.end() && w >= it->c; ++it)
                pq.emplace(*it);
            if (!pq.empty()) {
                w += pq.top().p;
                pq.pop();
            }
        }
        return w;
    }
};

