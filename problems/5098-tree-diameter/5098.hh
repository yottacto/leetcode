#include <vector>
#include <utility>

struct Solution
{
    std::vector<std::vector<int>> tree;

    std::pair<int, int> dfs(int u, int parent)
    {
        auto max = 1;
        auto ru = u;
        for (auto v : tree[u]) {
            if (v == parent)
                continue;
            auto [w, dw] = dfs(v, u);
            if (dw + 1 > max) {
                max = dw + 1;
                ru = w;
            }
        }
        return {ru, max};
    }

    int treeDiameter(std::vector<std::vector<int>>& edges)
    {
        int n = edges.size() + 1;
        tree.clear();
        tree.resize(n);
        for (auto const& e : edges) {
            auto u = e[0];
            auto v = e[1];
            tree[u].emplace_back(v);
            tree[v].emplace_back(u);
        }
        auto [u, _] = dfs(0, -1);
        return dfs(u, -1).second - 1;
    }
};

