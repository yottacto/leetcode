#pragma once
#include <vector>
#include <queue>

auto constexpr maxn = 200;

std::vector<std::vector<int>> dir{
    {-1, 0},
    {+1, 0},
    {0, -1},
    {0, +1},
};

struct data
{
    data(int x, int y, int h)
        : x(x), y(y), h(h) {}
    int x;
    int y;
    int h;
};

auto operator<(data const& lhs, data const& rhs)
{
    return lhs.h > rhs.h;
}

struct Solution
{
    bool vis[maxn][maxn] = {};
    int n;
    int m;

    auto inrange(int x, int l, int r) { return l <= x && x < r; }
    auto inrange(int x, int y) { return inrange(x, 0, n) && inrange(y, 0, m); }

    int trapRainWater(std::vector<std::vector<int>>& map)
    {
        if (map.empty())
            return 0;
        n = map.size();
        m = map[0].size();
        std::priority_queue<data> pq;
        for (auto i = 0; i < n; i++) {
            pq.emplace(i, 0, map[i][0]);
            pq.emplace(i, m - 1, map[i][m - 1]);
            vis[i][0] = vis[i][m - 1] = true;
        }
        for (auto i = 0; i < m; i++) {
            pq.emplace(0, i, map[0][i]);
            pq.emplace(n - 1, i, map[n - 1][i]);
            vis[0][i] = vis[n - 1][i] = true;
        }
        auto res = 0;
        while (!pq.empty()) {
            auto now = pq.top();
            pq.pop();
            for (auto const& d : dir) {
                auto nx = now.x + d[0];
                auto ny = now.y + d[1];
                if (!inrange(nx, ny) || vis[nx][ny])
                    continue;
                if (now.h > map[nx][ny]) {
                    res += now.h - map[nx][ny];
                    map[nx][ny] = now.h;
                }
                pq.emplace(nx, ny, map[nx][ny]);
                vis[nx][ny] = true;
            }
        }
        return res;
    }
};

