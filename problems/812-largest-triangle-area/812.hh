#include <algorithm>
#include <cmath>

struct Solution
{
    using point_type = std::vector<int>;

    double area(point_type const& a, point_type const& b, point_type const& c)
    {
        auto x1 = b[0] - a[0];
        auto y1 = b[1] - a[1];
        auto x2 = c[0] - a[0];
        auto y2 = c[1] - a[1];
        return std::abs(x1 * y2 - x2 * y1) / 2.;
    }

    double largestTriangleArea(std::vector<std::vector<int>>& points)
    {
        int n = points.size();
        double res = 0;
        for (auto i = 0; i < n; i++)
            for (auto j = i + 1; j < n; j++)
                for (auto k = j + 1; k < n; k++)
                    res = std::max(res, area(points[i], points[j], points[k]));
        return res;
    }
};

