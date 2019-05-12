#pragma once
#include <vector>

struct Solution
{
    std::vector<std::vector<int>> g;
    std::vector<int> color;
    std::vector<int> vis;
    std::vector<std::set<int>> ava;

    void dfs(int u)
    {
        vis[u] = true;
        color[u] = *ava[u].begin();
        for (auto v : g[u])
            if (!vis[v])
                ava[v].erase(color[u]);
        for (auto v : g[u])
            if (!vis[v])
                dfs(v);
    }

    std::vector<int> gardenNoAdj(int n, std::vector<std::vector<int>>& paths)
    {
        g.resize(n);
        color.resize(n);
        vis.resize(n + 1);
        ava.resize(n, {1, 2, 3, 4});
        for (auto const& e : paths) {
            auto u = e[0] - 1;
            auto v = e[1] - 1;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        for (auto i = 0; i < n; i++)
            if (!vis[i])
                dfs(i);
        return color;
    }
};

