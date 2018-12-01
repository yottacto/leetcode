#pragma once
#include <vector>
#include <utility>

struct Solution
{
    std::vector<std::vector<int>> g;
    std::vector<int> path;

    void add_edge(int u, int v)
    {
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    std::pair<int, int> dfs(int u, std::vector<int>& record, int parent = -1, int depth = 1)
    {
        record.emplace_back(u);
        std::pair<int, int> res{depth, u};
        for (auto v : g[u]) {
            if (v == parent) continue;
            res = std::max(res, dfs(v, record, u, depth + 1));
        }
        if (depth > (int)path.size())
            path = record;
        record.pop_back();
        return res;
    }

    std::vector<int> findMinHeightTrees(
        int n,
        std::vector<std::pair<int, int>>& edges
    )
    {
        g.resize(n);
        for (auto const& e : edges)
            add_edge(e.first, e.second);

        std::vector<int> record;
        auto u = dfs(0, record).second;
        dfs(u, record);

        int len = path.size();
        if (len&1)
            return {path[len/2]};
        else
            return {path[len/2], path[len/2 - 1]};
    }
};

