#pragma once
#include <vector>

struct Solution
{
    int f[60][60][60] = {};
    int n;

    auto inrange(int x, int l, int r)
    {
        return l <= x && x < r;
    }

    int cherryPickup(std::vector<std::vector<int>>& grid)
    {
        n = grid.size();
        f[0][0][0] = grid[0][0];
        for (auto x1 = 0; x1 < n; x1++)
            for (auto y1 = 0; y1 < n; y1++)
                for (auto x2 = 0; x2 < n; x2++) {
                    if (!x1 && !y1 && !x2)
                        continue;
                    auto y2 = x1 + y1 - x2;
                    if (!inrange(y2, 0, n))
                        continue;
                    if (grid[x1][y1] == -1 || grid[x2][y2] == -1) {
                        f[x1][y1][x2] = -1;
                        continue;
                    }
                    auto add = grid[x1][y1] + grid[x2][y2];
                    if (x1 == x2) add -= grid[x1][y1];
                    auto t = -1;
                    if (y1 > 0 && y2 > 0 && f[x1][y1 - 1][x2] != -1)
                        t = f[x1][y1 - 1][x2] + add;
                    if (y1 > 0 && x2 > 0 && f[x1][y1 - 1][x2 - 1] != -1)
                        t = std::max(t, f[x1][y1 - 1][x2 - 1] + add);
                    if (x1 > 0 && y2 > 0 && f[x1 - 1][y1][x2] != -1)
                        t = std::max(t, f[x1 - 1][y1][x2] + add);
                    if (x1 > 0 && x2 > 0 && f[x1 - 1][y1][x2 - 1] != -1)
                        t = std::max(t, f[x1 - 1][y1][x2 - 1] + add);
                    f[x1][y1][x2] = t;
                }
        return std::max(0, f[n - 1][n - 1][n - 1]);
    }
};

