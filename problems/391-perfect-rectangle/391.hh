#pragma once
#include <vector>
#include <algorithm>
#include <map>
#include <utility>

struct Solution
{
    bool isRectangleCover(std::vector<std::vector<int>>& rectangles)
    {
        std::map<std::pair<int, int>, int> count;
        auto minx = rectangles[0][0];
        auto maxx = rectangles[0][0];
        auto miny = rectangles[0][1];
        auto maxy = rectangles[0][1];
        auto sum = 0;
        for (auto const& rect : rectangles) {
            minx = std::min(minx, std::min(rect[0], rect[2]));
            maxx = std::max(maxx, std::max(rect[0], rect[2]));
            miny = std::min(miny, std::min(rect[1], rect[3]));
            maxy = std::max(maxy, std::max(rect[1], rect[3]));
            sum += (rect[2] - rect[0]) * (rect[3] - rect[1]);
            count[{rect[0], rect[1]}]++;
            count[{rect[0], rect[3]}]++;
            count[{rect[2], rect[1]}]++;
            count[{rect[2], rect[3]}]++;
        }
        if (sum != (maxx - minx) * (maxy - miny))
            return false;
        if (count[{minx, miny}] != 1 || count[{minx, maxy}] != 1
                || count[{maxx, miny}] != 1 || count[{maxx, maxy}] != 1)
            return false;
        count[{minx, miny}] = count[{minx, maxy}]
            = count[{maxx, miny}] = count[{maxx, maxy}] = 0;
        for (auto const& c : count)
            if (c.second & 1)
                return false;
        return true;
    }
};

