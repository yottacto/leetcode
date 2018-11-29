#pragma once
#include <algorithm>
#include <vector>

auto constexpr inf = 1 << 30;

struct Solution
{
    int minimumTotal(std::vector<std::vector<int>> const& triangle)
    {
        int n = triangle.size();
        std::vector<int> prev(n + 2, inf);
        std::vector<int> now(n + 2, inf);

        now[1] = triangle[0][0];
        for (auto i = 2; i <= n; i++) {
            std::swap(now, prev);
            for (auto j = 1; j <= i; j++)
                now[j] = std::min(prev[j], prev[j - 1]) + triangle[i - 1][j - 1];
        }

        return *std::min_element(now.begin(), now.end());
    }
};

