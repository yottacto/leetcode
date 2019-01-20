#pragma once
#include <vector>

int f[(1<<21) + 10][22]={};

struct Solution
{
    int n;
    int m;
    int start;
    int end;

    std::vector<std::vector<int>> dir{
        {-1, 0}, {1, 0},
        {0, -1}, {0, 1},
    };

    int uniquePathsIII(std::vector<std::vector<int>> const& grid)
    {
        n = grid.size();
        m = grid[0].size();
        auto target = 0;
        for (auto i = 0; i < n; i++)
            for (auto j = 0; j < m; j++) {
                auto t = i * m + j;
                if (grid[i][j] == 1)
                    start = t;
                if (grid[i][j] == 2)
                    end = t;
                if (grid[i][j] != -1)
                    target |= 1<<t;
            }
        for (auto i = 0; i < (1<<(n*m)); i++)
            for (auto j = 0; j < (n * m); j++)
                f[i][j] = 0;
        f[1<<start][start] = 1;
        for (auto i = 0; i < (1<<(n*m)); i++) {
            for (auto j = 0; j < (n*m); j++) {
                if (!(i & (1<<j)))
                    continue;
                auto ts = i ^ (1<<j);
                auto x = j / m;
                auto y = j % m;
                if (grid[x][y] == -1) continue;
                for (auto const& d : dir) {
                    auto tx = x + d[0];
                    auto ty = y + d[1];
                    if (!(0 <= tx && tx < n && 0 <= ty && ty < m))
                        continue;
                    auto t = tx * m + ty;
                    if (!(ts & (1<<t)))
                        continue;
                    f[i][j] += f[ts][t];
                }
            }
        }
        return f[target][end];
    }
};

