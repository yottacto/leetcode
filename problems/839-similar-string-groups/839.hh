#pragma once
#include <vector>
#include <string>
#include <unordered_set>
#include <numeric>

struct dsu
{
    dsu(int n) : n(n), parent(n)
    {
        std::iota(parent.begin(), parent.end(), 0);
    }

    auto get_parent(int i) -> int
    {
        return i == parent[i]
            ? i
            : parent[i] = get_parent(parent[i]);
    }

    auto connected(int i, int j)
    {
        return get_parent(i) == get_parent(j);
    }

    auto connect(int i, int j)
    {
        auto ti = get_parent(i);
        auto tj = get_parent(j);
        if (ti != tj)
            parent[ti] = tj;
    }

    auto count()
    {
        for (auto& i : parent)
            i = get_parent(i);
        std::unordered_set<int> id{parent.begin(), parent.end()};
        return id.size();
    }

    int n;
    std::vector<int> parent;
};

struct Solution
{
    auto similar(std::string const& a, std::string const& b)
    {
        if (a.size() != b.size())
            return false;
        int first = -1;
        int second = -1;
        for (auto i = 0; i < (int)a.size(); i++)
            if (a[i] != b[i]) {
                if (second != -1) {
                    return false;
                } else if (first != -1) {
                    second = i;
                    if (a[first] != b[second] || a[second] != b[first])
                        return false;
                } else {
                    first = i;
                }
            }
        return (first != -1 && second != -1)
            || (first == -1 && second == -1);
    }

    int numSimilarGroups(std::vector<std::string>& a)
    {
        int n = a.size();
        dsu dsu(n);
        for (auto i = 0; i < n; i++)
            for (auto j = i + 1; j < n; j++) {
                if (dsu.connected(i, j))
                    continue;
                if (similar(a[i], a[j]))
                    dsu.connect(i, j);
            }
        return dsu.count();
    }
};

