#pragma once
#include <vector>

struct Solution
{
    int n;
    int m;
    int sum[303][303] = {0};
    std::unordered_map<int, int> count;

    int calc(std::vector<int> const& a, int l, int r, int target)
    {
        auto res = 0;
        count[0] = 1;
        for (auto i : a) {
            if (count.count(i - target))
                res += count[i - target];
            count[i]++;
        }
        for (auto i : a)
            count[i] = 0;
        return res;
    }

    int numSubmatrixSumTarget(std::vector<std::vector<int>>& matrix, int target)
    {
        n = matrix.size();
        m = matrix[0].size();
        for (auto i = 0; i < n; i++)
        for (auto j = 0; j < m; j++) {
            sum[i + 1][j + 1] = matrix[i][j] + sum[i][j + 1] + sum[i + 1][j]
                - sum[i][j];
        }

        auto count = 0;
        std::vector<int> a(n);
        for (auto y = 0; y < m; y++)
            for (auto y2 = y; y2 < m; y2++) {
                for (auto i = 0; i < n; i++)
                    a[i] = sum[i + 1][y2 + 1] - sum[i + 1][y];
                auto tmp = calc(a, 0, n - 1, target);
                count += tmp;
            }

        return count;
    }
};

