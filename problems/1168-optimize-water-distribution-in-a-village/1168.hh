#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>

struct Solution
{
    using edge_type = std::pair<int, int>;

    std::vector<int> parent;

    int get_parent(int u)
    {
        return u == parent[u]
            ? u
            : parent[u] = get_parent(parent[u]);
    }

    void set_union(int u, int v)
    {
        auto tu = get_parent(u);
        auto tv = get_parent(v);
        if (tu != tv)
            parent[tu] = tv;
    }

    int minCostToSupplyWater(int n, std::vector<int>& wells, std::vector<std::vector<int>>& pipes)
    {
        parent.resize(n + 2);
        std::iota(parent.begin(), parent.end(), 0);

        for (auto i = 0; i < n; i++)
            pipes.emplace_back(std::vector<int>{n + 1, i + 1, wells[i]});
        std::sort(pipes.begin(), pipes.end(), [](auto const& a, auto const& b) {
            return a[2] < b[2];
        });
        auto res = 0;
        for (auto i = 0; i < (int)pipes.size(); i++) {
            auto u = pipes[i][0];
            auto v = pipes[i][1];
            auto w = pipes[i][2];
            if (get_parent(u) == get_parent(v))
                continue;
            res += w;
            set_union(u, v);
        }
        return res;
    }
};

