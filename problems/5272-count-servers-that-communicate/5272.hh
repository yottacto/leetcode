#include <vector>

struct Solution
{
    int countServers(std::vector<std::vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        std::vector<int> row(n);
        std::vector<int> col(m);
        for (auto i = 0; i < n; i++)
            for (auto j = 0; j < m; j++)
                if (grid[i][j]) {
                    row[i]++;
                    col[j]++;
                }
        auto res = 0;
        for (auto i = 0; i < n; i++)
            for (auto j = 0; j < m; j++)
                if (grid[i][j] && (row[i] > 1 || col[j] > 1))
                    res++;
        return res;
    }
};

