#include <vector>
#include <queue>

struct Solution
{
    int dis(std::vector<int> const& p)
    {
        return p[0] * p[0] + p[1] * p[1];
    }

    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k)
    {
        int n = points.size();
        auto cmp = [&](auto i, auto j) {
            return dis(points[i]) < dis(points[j]);
        };
        std::priority_queue<int, std::vector<int>, decltype(cmp)> pq{cmp};
        for (auto i = 0; i < n; i++) {
            pq.emplace(i);
            if (static_cast<int>(pq.size()) > k)
                pq.pop();
        }
        std::vector<std::vector<int>> res;
        for (; !pq.empty(); pq.pop())
            res.emplace_back(points[pq.top()]);
        return res;
    }
};

