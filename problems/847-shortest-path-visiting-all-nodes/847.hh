#pragma once
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <unordered_map>

auto constexpr maxn = 12;
auto constexpr inf = 1 << 30;

#include <iostream>

struct Solution
{
    int n;
    int f[1<<maxn][maxn];
    bool table[maxn][maxn] = {};
    bool inqueue[1<<maxn][maxn] = {};

    int shortestPathLength(std::vector<std::vector<int>>& graph)
    {
        n = graph.size();
        for (auto i = 0; i < n; i++)
            for (auto j : graph[i])
                table[i][j] = true;

        std::fill(&f[0][0], &f[0][0] + sizeof(f) / sizeof(f[0][0]), inf);
        std::queue<std::pair<int, int>> q;
        for (auto i = 0; i < n; i++) {
            f[1 << i][i] = 0;
            q.emplace(1<<i, i);
        }
        while (!q.empty()) {
            auto now = q.front();
            q.pop();
            auto i = now.first;
            auto last = now.second;
            inqueue[i][last] = false;
            for (auto j = 0; j < n; j++) {
                if (j == last || !table[last][j]) continue;
                auto s = i | (1<<j);
                if (f[s][j] > f[i][last] + 1) {
                    f[s][j] = f[i][last] + 1;
                    if (!inqueue[s][j]) {
                        q.emplace(s, j);
                        inqueue[s][j] = true;
                    }
                }
            }
        }

        auto res = inf;
        for (auto i = 0; i < n; i++)
            res = std::min(res, f[(1<<n) - 1][i]);
        return res;
    }
};

