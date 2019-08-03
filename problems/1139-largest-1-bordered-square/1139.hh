#include <vector>

struct Solution
{
    int largest1BorderedSquare(std::vector<std::vector<int>>& grid)
    {
        if (grid.empty())
            return 0;
        int n = grid.size();
        int m = grid[0].size();
        std::vector<std::vector<int>> rows(n + 1, std::vector<int>(m + 1));
        std::vector<std::vector<int>> cols(n + 1, std::vector<int>(m + 1));
        for (auto i = 0; i < n; i++)
            for (auto j = 0; j < m; j++)
                rows[i + 1][j + 1] = rows[i + 1][j] + grid[i][j];
        for (auto j = 0; j < m; j++)
            for (auto i = 0; i < n; i++)
                cols[i + 1][j + 1] = cols[i][j + 1] + grid[i][j];

        return [&]() {
            for (auto l = std::min(n, m); l >= 1; l--) {
                for (auto i = 1; i + l - 1 <= n; i++)
                    for (auto j = 1; j + l - 1 <= m; j++) {
                        auto count_row0 = rows[i][j + l - 1] - rows[i][j - 1];
                        auto count_row1 = rows[i + l - 1][j + l - 1] - rows[i + l - 1][j - 1];
                        auto count_col0 = cols[i + l - 1][j] - cols[i - 1][j];
                        auto count_col1 = cols[i + l - 1][j + l - 1] - cols[i - 1][j + l - 1];
                        if (count_row0 == l
                            && count_row1 == l
                            && count_col0 == l
                            && count_col1 == l
                        ) {
                            return l * l;
                        }
                    }
            }
            return 0;
        }();
    }
};

