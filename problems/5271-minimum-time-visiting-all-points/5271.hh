#include <vector>
#include <algorithm>
#include <cmath>

struct Solution
{
    template <class T>
    int calc(T const& p1, T const& p2)
    {
        auto dx = std::abs(p1[0] - p2[0]);
        auto dy = std::abs(p1[1] - p2[1]);
        return std::max(dx, dy);
    }

    int minTimeToVisitAllPoints(std::vector<std::vector<int>>& points)
    {
        auto res = 0;
        int n = points.size();
        for (auto i = 1; i < n; i++)
            res += calc(points[i - 1], points[i]);
        return res;
    }
};

