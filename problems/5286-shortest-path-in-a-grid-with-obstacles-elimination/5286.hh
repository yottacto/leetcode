#include <bits/stdc++.h>

struct _data
{
    int x;
    int y;
    int k;
};

struct Solution
{
    std::vector<std::vector<std::vector<int>>> dis;
    std::vector<std::vector<int>> dir{
        {-1, 0},
        {+1, 0},
        {0, -1},
        {0, +1},
    };
    int n;
    int m;

    bool inrange(int x, int y)
    {
        return (0 <= x && x < n)
            && (0 <= y && y < m);
    }

    int shortestPath(std::vector<std::vector<int>>& grid, int k)
    {
        n = grid.size();
        m = grid[0].size();
        dis.resize(n, std::vector<std::vector<int>>(m, std::vector<int>(k + 1, -1)));
        std::queue<_data> q;
        q.emplace(_data{0, 0, k});
        dis[0][0][k] = 0;
        while (!q.empty()) {
            auto now = q.front();
            q.pop();
            if (now.x == n - 1 && now.y == m - 1)
                return dis[now.x][now.y][now.k];
            for (auto const& d : dir) {
                auto next = now;
                next.x += d[0];
                next.y += d[1];
                if (!inrange(next.x, next.y))
                    continue;
                if (grid[next.x][next.y])
                    next.k--;
                if (next.k < 0 || dis[next.x][next.y][next.k] != -1)
                    continue;
                q.emplace(next);
                dis[next.x][next.y][next.k] = dis[now.x][now.y][now.k] + 1;
            }
        }
        return -1;
    }
};

