#include <vector>
#include <algorithm>

auto constexpr inf = 1<<30;

struct Solution
{
    std::vector<int> shortestDistanceColor(std::vector<int>& colors, std::vector<std::vector<int>>& queries)
    {
        int n = colors.size();
        std::vector<std::vector<int>> left(4, std::vector<int>(n + 2, inf));
        std::vector<std::vector<int>> right(4, std::vector<int>(n + 2, inf));
        std::vector<std::vector<int>> dis(4, std::vector<int>(n + 2, inf));
        for (auto i = 1; i <= n; i++) {
            for (auto j = 1; j <= 3; j++)
                if (colors[i - 1] == j)
                    left[j][i] = 0;
                else if (left[j][i - 1] != inf)
                    left[j][i] = left[j][i - 1] + 1;
        }
        for (auto i = n; i >= 1; i--) {
            for (auto j = 1; j <= 3; j++)
                if (colors[i - 1] == j)
                    right[j][i] = 0;
                else if (right[j][i + 1] != inf)
                    right[j][i] = right[j][i + 1] + 1;
        }
        for (auto i = 1; i <= n; i++) {
            for (auto j = 1; j <= 3; j++) {
                dis[j][i] = std::min(left[j][i], right[j][i]);
                if (dis[j][i] == inf)
                    dis[j][i] = -1;
            }
        }
        std::vector<int> res;
        for (auto const& q : queries)
            res.emplace_back(dis[q[1]][q[0] + 1]);
        return res;
    }
};

