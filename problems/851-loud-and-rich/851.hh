#pragma once
#include <algorithm>
#include <numeric>
#include <vector>

#include <iostream>

struct Solution
{
    std::vector<std::vector<int>> graph;
    std::vector<char> vis;
    std::vector<int> ans;

    void add_edge(int u, int v)
    {
        graph[u].emplace_back(v);
    }

    auto dfs(int u, std::vector<int> const& quiet)
    {
        if (vis[u]) return ans[u];
        vis[u] = 1;
        for (auto v : graph[u])
            if (quiet[dfs(v, quiet)] < quiet[ans[u]])
                ans[u] = ans[v];
        return ans[u];
    }

    std::vector<int> loudAndRich(
        std::vector<std::vector<int>> const& richer,
        std::vector<int> const& quiet
    )
    {
        int n = quiet.size();
        graph.resize(n);
        for (auto const& e : richer)
            add_edge(e[1], e[0]);
        vis.resize(n);
        ans.resize(n);
        std::iota(ans.begin(), ans.end(), 0);
        for (auto i = 0; i < n; i++) {
            if (vis[i]) continue;
            dfs(i, quiet);
        }
        return ans;
    }
};

