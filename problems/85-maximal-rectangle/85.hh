#pragma once
#include <algorithm>
#include <vector>

struct Solution
{
    auto max_rect(std::vector<int> const& h)
    {
        int n = h.size();
        std::vector<int> q;
        q.reserve(n);
        auto max = 0;
        for (auto i = 0; i < n; i++) {
            while (!q.empty() && h[q.back()] >= h[i]) {
                auto th = h[q.back()];
                q.pop_back();
                auto left = q.empty() ? -1 : q.back();
                max = std::max(max, th * (i - left - 1));
            }
            q.emplace_back(i);
        }
        return max;
    }

    int maximalRectangle(std::vector<std::vector<char>>& mat)
    {
        if (mat.empty()) return 0;
        int n = mat.size();
        int m = mat[0].size();
        std::vector<int> h(m + 1);
        auto max = 0;
        for (auto i = 0; i < n; i++) {
            for (auto j = 0; j < m; j++)
                h[j] = mat[i][j] == '1' ? h[j] + 1 : 0;
            max = std::max(max, max_rect(h));
        }
        return max;
    }
};

