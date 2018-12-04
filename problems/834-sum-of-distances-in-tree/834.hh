#pragma once
#include <vector>

struct Solution
{
    int n;
    std::vector<std::vector<int>> g;
    std::vector<int> res;
    std::vector<int> sub;

    void add_edge(int u, int v)
    {
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    void dfs(int u, int parent = -1)
    {
        sub[u] = 1;
        for (auto v : g[u]) {
            if (v == parent) continue;
            dfs(v, u);
            sub[u] += sub[v];
            res[u] += res[v] + sub[v];
        }
    }

    void push_down(int u, int parent = -1)
    {
        if (parent != -1) {
            res[u] = res[parent] - sub[u] + n - sub[u];
        }
        for (auto v : g[u]) {
            if (v == parent) continue;
            push_down(v, u);
        }
    }

    std::vector<int> sumOfDistancesInTree(int n, std::vector<std::vector<int>>& edges)
    {
        this->n = n;
        g.resize(n);
        for (auto const& e : edges)
            add_edge(e[0], e[1]);
        res.resize(n);
        sub.resize(n);
        dfs(0);
        push_down(0);
        return res;
    }
};

