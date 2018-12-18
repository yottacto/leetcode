#pragma once
#include <algorithm>
#include <vector>

auto constexpr maxn = 107;

struct Solution
{
    int f[maxn][maxn][maxn] = {};
    int n;
    std::vector<int> boxes;

    int dfs(int l, int r, int k)
    {
        if (l > r) return 0;
        if (f[l][r][k])
            return f[l][r][k];
        for (; r > l && boxes[r - 1] == boxes[r]; r--)
            k++;
        f[l][r][k] = dfs(l, r - 1, 0) + (k + 1) * (k + 1);
        for (auto i = r - 1; i >= l; i--) {
            if (boxes[i] != boxes[r]) continue;
            f[l][r][k] = std::max(f[l][r][k], dfs(l, i, k + 1) + dfs(i + 1, r - 1, 0));
        }
        return f[l][r][k];
    }

    int removeBoxes(std::vector<int>& boxes)
    {
        this->boxes = boxes;
        n = boxes.size();
        return dfs(0, n - 1, 0);
    }
};

