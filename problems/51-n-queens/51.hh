#pragma once
#include <vector>
#include <string>
#include <cmath>

struct Solution
{
    std::vector<int> pos;
    std::vector<std::vector<std::string>> res;
    int n;


    void dfs(int depth, int state)
    {
        if (depth == n) {
            res.emplace_back(n, std::string(n, '.'));
            for (auto i = 0; i < n; i++)
                res.back()[i][pos[i]] = 'Q';
            return;
        }

        for (auto i = 0; i < n; i++) {
            if (state & (1<<i)) continue;
            auto diag = [&]() {
                for (auto j = 0; j < depth; j++)
                    if (depth - j == abs(pos[j] - i))
                        return true;
                return false;
            };
            if (diag()) continue;
            pos[depth] = i;
            dfs(depth + 1, state | (1<<i));
        }
    }

    std::vector<std::vector<std::string>> solveNQueens(int n)
    {
        this->n = n;
        pos.resize(n);
        dfs(0, 0);
        return res;
    }
};

