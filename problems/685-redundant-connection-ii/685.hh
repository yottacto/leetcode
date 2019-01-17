#pragma once
#include <algorithm>
#include <vector>

struct edge
{
    edge(int to, int id) : to(to), id(id) {}
    int to;
    int id;
};

struct Solution
{
    std::vector<std::vector<edge>> g;
    std::vector<std::vector<int>> parent;
    std::vector<char> vis;
    std::vector<int> path;
    std::vector<int> indegree;
    int max{-1};
    int root{-1};
    int n;

    template <class Edges>
    auto dfs(int u, Edges const& edges)
    {
        vis[u] = true;
        for (auto const& e : g[u]) {
            auto v = e.to;
            auto id = e.id;
            path.emplace_back(id);
            if (vis[v]) {
                int i = path.size() - 1;
                for (; edges[path[i]][0] != v && i >= 0; i--)
                    max = std::max(max, path[i]);
                if (i == -1)
                    max = std::max(parent[v][0], parent[v][1]);
                else if (root)
                    max = id;
                else
                    max = std::max(max, path[i]);
                return true;
            }
            if (dfs(v, edges)) return true;
            path.pop_back();
        }
        return false;
    }

    std::vector<int> findRedundantDirectedConnection(std::vector<std::vector<int>> const& edges)
    {
        n = edges.size();
        parent.resize(n + 1);
        g.resize(n + 1);
        vis.resize(n + 1);
        indegree.resize(n + 1);
        for (auto i = 0u; i < edges.size(); i++) {
            auto const& e = edges[i];
            parent[e[1]].emplace_back(i);
            g[e[0]].emplace_back(e[1], i);
            indegree[e[1]]++;
        }
        for (auto i = 1; i <= n; i++)
            if (!indegree[i])
                root = i;
        if (root != -1) {
            dfs(root, edges);
            return edges[max];
        }
        for (auto i = 1; i <= n; i++) {
            if (vis[i]) continue;
            if (dfs(i, edges))
                return edges[max];
        }
        return {};
    }
};

