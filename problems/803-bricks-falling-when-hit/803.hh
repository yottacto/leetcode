#pragma once
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <numeric>

struct Solution
{
    int n;
    int m;
    std::vector<int> parent;
    std::vector<int> size;

    std::vector<std::vector<int>> dir{
        {1, 0}, {-1, 0}, {0, 1}, {0, -1},
    };

    auto inrange(int x, int l, int r)
    {
        return l <= x && x < r;
    }

    auto id(int x, int y)
    {
        return x * m + y;
    }

    int get_parent(int x)
    {
        return x == parent[x]
            ? x
            : parent[x] = get_parent(parent[x]);
    }

    void set_union(int x, int y)
    {
        auto tx = get_parent(x);
        auto ty = get_parent(y);
        if (tx != ty) {
            parent[tx] = ty;
            size[ty] += size[tx];
        }
    }

    std::vector<int> hitBricks(std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& hits)
    {
        n = grid.size();
        m = grid[0].size();
        auto a = grid;
        for (auto const& h : hits)
            a[h[0]][h[1]] = 0;
        parent.resize(n * m + 1);
        size.resize(n * m + 1, 1);
        size[0] = 0;
        std::iota(parent.begin(), parent.end(), 0);
        for (auto i = 0; i < m; i++)
            if (a[0][i] == 1)
                set_union(id(0, i), n * m);
        for (auto i = 0; i < n; i++)
            for (auto j = 0; j < m; j++) {
                if (a[i][j] != 1) continue;
                for (auto const& d : dir) {
                    auto tx = i + d[0];
                    auto ty = j + d[1];
                    if (!inrange(tx, 0, n) || !inrange(ty, 0, m) || a[tx][ty] != 1)
                        continue;
                    set_union(id(tx, ty), id(i, j));
                }
            }
        std::vector<int> res;
        for (auto it = hits.rbegin(); it != hits.rend(); ++it) {
            auto x = (*it)[0];
            auto y = (*it)[1];
            if (!grid[x][y]) {
                res.emplace_back(0);
                continue;
            }
            auto before = size[get_parent(n * m)];
            std::vector<int> to_connect;
            for (auto const& d : dir) {
                auto tx = x + d[0];
                auto ty = y + d[1];
                if (!inrange(tx, 0, n) || !inrange(ty, 0, m) || a[tx][ty] != 1)
                    continue;
                to_connect.emplace_back(id(tx, ty));
            }
            if (!x) to_connect.emplace_back(n * m);
            for (auto i : to_connect)
                set_union(i, to_connect[0]);
            auto after = size[get_parent(n * m)];
            res.emplace_back(after - before);

            a[x][y] = 1;
            if (!to_connect.empty())
                set_union(id(x, y), to_connect.front());
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};

