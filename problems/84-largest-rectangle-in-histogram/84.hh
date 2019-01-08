#pragma once
#include <algorithm>
#include <vector>
#include <queue>

struct Solution
{
    int n;
    std::vector<int> left;
    std::vector<int> right;

    void calc(std::vector<int> const& h, std::vector<int>& d, bool left = true)
    {
        d.resize(n);
        std::deque<int> dq;
        for (auto i = left ? 0 : n - 1; left ? i < n : i >= 0; left ? i++ : i--) {
            while (!dq.empty() && h[dq.back()] >= h[i])
                dq.pop_back();
            d[i] = dq.empty()
                ? (left ? -1 : n)
                : dq.back();
            dq.emplace_back(i);
        }

    }

    int largestRectangleArea(std::vector<int> const& heights)
    {
        n = heights.size();
        calc(heights, left);
        calc(heights, right, false);
        auto max = 0;
        for (auto i = 0; i < n; i++)
            max = std::max(max, (right[i] - left[i] - 1) * heights[i]);
        return max;
    }
};

