#pragma once
#include <vector>
#include <unordered_set>
#include <queue>

struct Solution
{
    int numBusesToDestination(std::vector<std::vector<int>>& routes, int s, int t)
    {
        if (s == t) return 0;
        int n = routes.size();
        std::vector<std::unordered_set<int>> r;
        r.reserve(n);
        for (auto const& v : routes)
            r.emplace_back(v.begin(), v.end());
        std::unordered_set<int> target;
        std::queue<std::pair<int, int>> q;
        std::vector<char> vis(n);
        for (auto i = 0; i < n; i++) {
            if (r[i].count(t))
                target.emplace(i);
            if (r[i].count(s)) {
                q.emplace(i, 1);
                vis[i] = true;
            }
        }
        while (!q.empty()) {
            auto now = q.front();
            auto u = now.first;
            auto dis = now.second;
            q.pop();
            if (target.count(u))
                return dis;
            for (auto v = 0; v < n; v++) {
                if (vis[v]) continue;
                auto adj = [&]() {
                    for (auto x : r[u])
                        if (r[v].count(x))
                            return true;
                    return false;
                };
                if (!adj()) continue;
                q.emplace(v, dis + 1);
                vis[v] = true;
            }
        }
        return -1;
    }
};

