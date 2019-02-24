#pragma once
#include <vector>
#include <string>
#include <numeric>

struct Solution
{
    int parent[30];

    int get_parent(int u)
    {
        return u == parent[u] ? u : parent[u] = get_parent(parent[u]);
    }

    void set_union(int u, int v)
    {
        auto tu = get_parent(u);
        auto tv = get_parent(v);
        if (tu != tv)
            parent[tu] = tv;
    }

    bool equationsPossible(std::vector<std::string>& equations)
    {
        std::vector<std::pair<int, int>> neq;
        std::iota(parent, parent + 30, 0);
        for (auto const& s : equations)
            if (s[1] == '=')
                set_union(s[0] - 'a', s[3] - 'a');
            else
                neq.emplace_back(s[0] - 'a', s[3] - 'a');
        for (auto const& p : neq)
            if (get_parent(p.first) == get_parent(p.second))
                return false;
        return true;
    }
};

