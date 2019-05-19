#pragma once
#include <vector>
#include <queue>
#include <algorithm>

struct Solution
{
    int lastStoneWeight(std::vector<int>& stones)
    {
        std::priority_queue<int> pq;
        for (auto s : stones)
            pq.emplace(s);

        while (pq.size() > 1)  {
            auto x = pq.top();
            pq.pop();
            auto y = pq.top();
            pq.pop();
            if (x > y) std::swap(x, y);
            if (x == y)
                continue;
            pq.emplace(y - x);
        }
        if (pq.empty())
            return 0;
        else
            return pq.top();
    }
};

