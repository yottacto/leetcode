#include <vector>
#include <queue>

struct Solution
{
    std::vector<int> in;
    std::vector<std::vector<int>> g;

    std::vector<int> findOrder(
        int n,
        std::vector<std::vector<int>>& prerequisites
    )
    {
        in.resize(n);
        g.resize(n);
        for (auto const& v : prerequisites) {
            g[v[1]].emplace_back(v[0]);
            in[v[0]]++;
        }
        std::queue<int> q;
        for (auto i = 0; i < n; i++)
            if (!in[i])
                q.emplace(i);
        int count = q.size();
        std::vector<int> res;
        res.reserve(n);
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            res.emplace_back(u);
            for (auto const& v : g[u]) {
                in[v]--;
                if (!in[v]) {
                    q.emplace(v);
                    count++;
                }
            }
        }
        if (count == n)
            return res;
        else
            return {};
    }
};

