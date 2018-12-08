#pragma once
#include <unordered_set>
#include <vector>
#include <queue>

auto constexpr maxn = 100;
std::vector<std::vector<int>> dir{
    {-1, 0},
    {+1, 0},
    {0, -1},
    {0, +1},
};

struct Solution
{
    std::vector<int> parent;
    std::vector<int> size;
    std::vector<std::vector<int>> grid;
    bool vis[maxn][maxn] = {};
    int n;
    int m;

    auto id(int x, int y) { return x * m + y; }
    auto inrange(int x, int l, int r) { return l <= x && x < r; }
    auto inrange(int x, int y) { return inrange(x, 0, n) && inrange(y, 0, m); }

    auto bfs(int x, int y)
    {
        auto p = id(x, y);
        std::queue<int> q;
        q.push(p);
        vis[x][y] = true;
        parent[p] = p;
        size[p] = 1;
        while (!q.empty()) {
            auto now = q.front();
            q.pop();
            auto x = now/m;
            auto y = now%m;
            for (auto const& d : dir) {
                auto nx = x + d[0];
                auto ny = y + d[1];
                if (!inrange(nx, ny) || !grid[nx][ny] || vis[nx][ny])
                    continue;
                auto tid = id(nx, ny);
                q.push(tid);
                vis[nx][ny] = true;
                parent[tid] = p;
                size[p]++;
            }
        }
    }

    int largestIsland(std::vector<std::vector<int>> const& grid)
    {
        this->grid = grid;
        n = grid.size();
        m = grid[0].size();
        parent.resize(n * m);
        size.resize(n * m);

        auto res = 0;
        for (auto i = 0; i < n; i++) {
            for (auto j = 0; j < m; j++) {
                if (vis[i][j] || !grid[i][j])
                    continue;
                bfs(i, j);
                res = std::max(res, size[id(i, j)]);
            }
        }

        for (auto i = 0; i < n; i++) {
            for (auto j = 0; j < m; j++) {
                if (grid[i][j]) continue;
                std::unordered_set<int> adj;
                for (auto const& d : dir) {
                    auto nx = i + d[0];
                    auto ny = j + d[1];
                    if (!inrange(nx, ny) || !grid[nx][ny])
                        continue;
                    adj.insert(parent[id(nx, ny)]);
                }
                auto sum = 1;
                for (auto t : adj)
                    sum += size[t];
                res = std::max(res, sum);
            }
        }
        return res;
    }
};

