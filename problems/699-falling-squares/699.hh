#pragma once
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <numeric>

struct data
{
    int left;
    int len;
    int height;
};

auto operator<(data const& a, data const& b)
{
    return a.left < b.left
        || (a.left == b.left && a.len < b.len);
}

struct Solution
{
    using pair = std::pair<int, int>;

    auto intersect(data const& a, data const& b)
    {
        return !(a.left + a.len - 1 < b.left
            || b.left + b.len - 1 < a.left);
    }

    std::vector<int> fallingSquares(std::vector<pair> const& pos)
    {
        int n = pos.size();
        std::vector<int> height;
        height.reserve(n);
        std::multiset<data> dropped;
        for (auto const& p : pos) {
            auto h = 0;
            auto now = data{p.first, p.second, 0};
            for (auto it = dropped.begin(); it != dropped.end(); ++it) {
                if (intersect(now, *it))
                    h = std::max(h, it->height);
                if (it->left > now.left + now.len - 1)
                    break;
            }
            height.emplace_back(now.height = h + now.len);
            dropped.insert(now);
        }
        std::partial_sum(height.begin(), height.end(), height.begin(), [](auto a, auto b) {
            return std::max(a, b);
        });
        return height;
    }
};

