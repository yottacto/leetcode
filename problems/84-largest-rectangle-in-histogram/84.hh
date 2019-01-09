#pragma once
#include <algorithm>
#include <vector>

struct Solution
{
    int largestRectangleArea(std::vector<int>& heights)
    {
        heights.emplace_back(0);
        int n = heights.size();
        std::vector<int> q;
        q.reserve(n);
        auto max = 0;
        for (auto i = 0; i < n; i++) {
            while (!q.empty() && heights[q.back()] >= heights[i]) {
                auto h = heights[q.back()];
                q.pop_back();
                auto left = q.empty() ? -1 : q.back();
                max = std::max(max, h * (i - left - 1));
            }
            q.emplace_back(i);
        }
        return max;
    }
};

