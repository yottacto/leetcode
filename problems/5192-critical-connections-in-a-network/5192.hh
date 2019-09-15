#include <vector>

struct Solution
{
    std::vector<std::vector<int>> res;
    std::vector<std::vector<int>> g;
    std::vector<int> low;
    std::vector<int> dfn;
    int tick{};

    void add_edge(int u, int v)
    {
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }


    void tarjan(int u, int f)
    {
        low[u] = dfn[u] = ++tick;
        for (auto v : g[u]) {
            if (v == f) continue;
            if (!dfn[v]) {
                tarjan(v, u);
                low[u] = std::min(low[u], low[v]);
                if (dfn[u] < low[v])
                    res.emplace_back(std::vector<int>{u, v});
            } else
                low[u] = std::min(low[u], dfn[v]);
        }
    }


    std::vector<std::vector<int>> criticalConnections(int n, std::vector<std::vector<int>>& connections)
    {
        g.resize(n);
        dfn.resize(n);
        low.resize(n);
        for (auto const& e : connections)
            add_edge(e[0], e[1]);

        tarjan(0, -1);
        return res;
    }
};

