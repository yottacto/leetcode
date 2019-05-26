#pragma once
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <map>
#include <cmath>
#include <cstring>

bool f[200][200][200];

struct Solution
{
    int lastStoneWeightII(std::vector<int>& stones)
    {
        std::memset(f, 0, sizeof(f));
        int n = stones.size();
        for (auto i = 0; i < n; i++)
            f[i][i][stones[i]] = true;
        for (auto l = 2; l <= n; l++) {
            for (auto i = 0; i + l - 1 < n; i++) {
                auto end = i + l - 1;
                for (auto mid = i; mid <= end; mid++) {
                    for (auto l = 0; l <= 100; l++)
                    for (auto r = 0; r <= 100; r++) {
                        if (f[i][mid][l] && f[mid + 1][end][r]) {
                            f[i][end][std::abs(r - l)] = true;
                        }
                    }
                }
            }
        }
        for (auto i = 0; i <= 100; i++)
            if (f[0][n - 1][i])
                return i;
        return 101;
    }
};

