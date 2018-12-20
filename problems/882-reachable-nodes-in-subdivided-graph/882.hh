#pragma once
#include <vector>
#include <queue>

auto constexpr maxn = 3007;
auto constexpr inf = 1<<30;

struct edge
{
    int end;
    int cost;
    int id;
};

auto operator<(edge const& lhs, edge const& rhs)
{
    return lhs.cost > rhs.cost;
}

struct Solution
{
    std::vector<std::vector<edge>> g;

    int reachableNodes(std::vector<std::vector<int>>& edges, int m, int n)
    {
        g.resize(n);
        for (int i = 0; i < (int)edges.size(); i++) {
            auto const& e = edges[i];
            auto u = e[0];
            auto v = e[1];
            auto c = e[2];
            g[u].emplace_back(edge{v, c + 1, i});
            g[v].emplace_back(edge{u, c + 1, i});
        }

        std::vector<int> dist(n, inf);
        dist[0] = 0;
        std::priority_queue<edge> pq;
        pq.emplace(edge{0, 0, 0});
        while (!pq.empty()) {
            auto now = pq.top();
            pq.pop();
            auto u = now.end;
            auto d = now.cost;
            if (dist[u] < d)
                continue;
            for (auto const& e : g[u]) {
                auto v = e.end;
                auto c = e.cost;
                if (d + c < dist[v]) {
                    dist[v] = d + c;
                    pq.emplace(edge{v, dist[v], 0});
                }
            }
        }

        std::vector<int> count(edges.size());
        auto res = 0;
        for (auto i = 0; i < n; i++) {
            if (dist[i] > m) continue;
            res++;
            auto rm = m - dist[i];
            for (auto const& e : g[i])
                count[e.id] += std::min(rm, e.cost - 1);
        }
        for (auto i = 0u; i < edges.size(); i++)
            res += std::min(count[i], edges[i][2]);
        return res;
    }
};

