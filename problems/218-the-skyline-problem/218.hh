#pragma once
#include <algorithm>
#include <vector>
#include <utility>
#include <set>

struct line
{
    line(bool in, int x, int h) : in(in), x(x), h(h) {}

    bool in;
    int x;
    int h;
};

auto operator<(line const& a, line const& b)
{
    return a.x < b.x
        || (a.x == b.x && a.in > b.in)
        || (a.x == b.x && a.in == b.in &&
            ((a.in && a.h > b.h) || (!a.in && a.h < b.h)));
}


struct Solution
{
    std::vector<std::pair<int, int>> getSkyline(std::vector<std::vector<int>>& buildings)
    {
        std::vector<line> lines;
        lines.reserve(buildings.size() * 2);
        for (auto const& b : buildings) {
            lines.emplace_back(true, b[0], b[2]);
            lines.emplace_back(false, b[1], b[2]);
        }
        std::sort(lines.begin(), lines.end());
        std::multiset<int, std::greater<int>> heights;
        heights.emplace(0);
        std::vector<std::pair<int, int>> res;
        for (auto const& l : lines)
            if (l.in) {
                if (l.h > *heights.begin())
                    res.emplace_back(l.x, l.h);
                heights.emplace(l.h);
            } else {
                heights.erase(heights.find(l.h));
                if (l.h > *heights.begin())
                    res.emplace_back(l.x, *heights.begin());
            }
        return res;
    }
};

