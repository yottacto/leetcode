#include <vector>

struct Solution
{
    bool checkStraightLine(std::vector<std::vector<int>>& points)
    {
        int n = points.size();
        bool all_x = true;
        for (auto i = 0; i < n; i++)
            if (points[i][0] != points[0][0]) {
                all_x = false;
                break;
            }
        if (all_x)
            return true;
        auto dx1 = points[1][0] - points[0][0];
        auto dy1 = points[1][1] - points[0][1];
        for (auto i = 1; i < n; i++) {
            if (points[i][0] == points[i - 1][0])
                return false;
            auto dx2 = points[i][0] - points[i - 1][0];
            auto dy2 = points[i][1] - points[i - 1][1];
            if (dx2 * dy1 != dx1 * dy2)
                return false;
        }
        return true;
    }
};

