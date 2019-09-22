#include <vector>

struct Solution
{
    std::vector<std::vector<int>> dir{
        {-1, 0}, {1, 0}, {0, 1}, {0, -1},
    };

    int surfaceArea(std::vector<std::vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        std::vector<std::vector<int>> a(n + 2, std::vector<int>(m + 2, 0));
        for (auto i = 0; i < n; i++)
            for (auto j = 0; j < m; j++)
                a[i + 1][j + 1] = grid[i][j];

        auto res = 0;
        for (auto i = 1; i <= n; i++) {
            for (auto j = 1; j <= m; j++) {
                if (a[i][j])
                    res += 2;
                for (auto const& d : dir) {
                    auto ni = i + d[0];
                    auto nj = j + d[1];
                    res += a[i][j] - std::min(a[i][j], a[ni][nj]);;
                }
            }
        }
        return res;
    }
};

