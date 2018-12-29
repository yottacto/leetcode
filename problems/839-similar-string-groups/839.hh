#pragma once
#include <vector>
#include <string>
#include <unordered_set>
#include <numeric>

struct dsu
{
    dsu(int n) : n(n), _size(n), parent(n)
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
        if (ti != tj) {
            parent[ti] = tj;
            _size--;
        }
    }

    auto size() const
    {
        return _size;
    }

    int n;
    int _size;
    std::vector<int> parent;
};

struct Solution
{
    auto similar(std::string const& a, std::string const& b)
    {
        auto count = 0;
        for (auto i = 0; i < (int)a.size(); i++)
            if (a[i] != b[i] && ++count > 2)
                return false;
        return true;
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
        return dsu.size();
    }
};

