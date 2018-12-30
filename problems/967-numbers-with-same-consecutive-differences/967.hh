#pragma once
#include <vector>
#include <cmath>

struct Solution
{
    std::vector<int> res;
    int n;
    int k;

    void dfs(int d, int num, int last = -1)
    {
        if (d == n) {
            res.emplace_back(num);
            return;
        }
        for (auto i = 0; i < 10; i++) {
            if (last == -1 && n > 1 && i == 0) continue;
            if (last == -1 || std::abs(i - last) == k)
                dfs(d + 1, num * 10 + i, i);
        }
    }

    std::vector<int> numsSameConsecDiff(int n, int k)
    {
        this->n = n;
        this->k = k;
        dfs(0, 0);
        return res;
    }
};

