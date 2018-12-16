#pragma once
#include <vector>

std::vector<std::vector<int>> dir{
    {-1, 0}, {1, 0},
    {0, -1}, {0, 1},
};

struct Solution
{
    int n;
    int m;

    std::vector<std::vector<int>> f;
    std::vector<std::vector<int>> mat;

    auto inrange(int x, int l, int r) { return l <= x && x < r; }
    auto inrange(int x, int y) { return inrange(x, 0, n) && inrange(y, 0, m); }

    int dp(int x, int y)
    {
        if (f[x][y] != -1)
            return f[x][y];
        f[x][y] = 1;
        for (auto const& d : dir) {
            auto nx = x + d[0];
            auto ny = y + d[1];
            if (!inrange(nx, ny) || mat[nx][ny] <= mat[x][y])
                continue;
            f[x][y] = std::max(f[x][y], dp(nx, ny) + 1);
        }
        return f[x][y];
    }

    int longestIncreasingPath(std::vector<std::vector<int>>& mat)
    {
        if (mat.empty())
            return 0;
        this->mat = mat;
        n = mat.size();
        m = mat[0].size();
        f.resize(n, std::vector<int>(m, -1));
        auto res = 0;
        for (auto i = 0; i < n; i++)
            for (auto j = 0; j < m; j++)
                res = std::max(res, dp(i, j));
        return res;
    }
};

