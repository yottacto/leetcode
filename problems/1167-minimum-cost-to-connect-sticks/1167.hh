#include <vector>
#include <queue>
#include <utility>

struct Solution
{
    int connectSticks(std::vector<int>& sticks)
    {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for (auto i : sticks)
            pq.emplace(i);
        auto sum = 0;
        while (pq.size() > 1) {
            auto x0 = pq.top();
            pq.pop();
            auto x1 = pq.top();
            pq.pop();
            sum += x0 + x1;
            pq.emplace(x0 + x1);
        }
        return sum;
    }
};

