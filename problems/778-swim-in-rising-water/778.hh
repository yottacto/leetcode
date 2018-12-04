#pragma once
#include <algorithm>
#include <vector>
#include <queue>

struct data
{
    data(int h, int x, int y) : h(h), x(x), y(y) {}

    int h;
    int x;
    int y;
};

auto operator<(data const& lhs, data const& rhs)
{
    return lhs.h > rhs.h;
}

std::vector<std::vector<int>> dir{
    {-1, 0},
    {+1, 0},
    {0, -1},
    {0, +1},
};


struct Solution
{
    int n;
    bool vis[100][100] = {};

    auto inrange(int x, int y)
    {
        return (0 <= x && x < n)
            && (0 <= y && y < n);
    }

    int swimInWater(std::vector<std::vector<int>>& grid)
    {
        n = grid.size();
        std::priority_queue<data> pq;
        pq.emplace(grid[0][0], 0, 0);
        vis[0][0] = true;
        auto max = 0;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            max = std::max(max, top.h);
            if (top.x == n-1 && top.y == n-1)
                return max;
            for (auto d : dir) {
                auto x = top.x + d[0];
                auto y = top.y + d[1];
                if (!inrange(x, y) || vis[x][y])
                    continue;
                vis[x][y] = true;
                pq.emplace(grid[x][y], x, y);
            }
        }
        return max;
    }
};

