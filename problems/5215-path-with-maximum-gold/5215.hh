#include <vector>

struct Solution
{
    int res{};
    int n;
    int m;

    std::vector<std::vector<int>> grid;
    std::vector<std::vector<int>> dir{
        {-1, 0},
        {+1, 0},
        {0, -1},
        {0, +1},
    };

    bool inrange(int x, int y)
    {
        return 0 <= x && x < n
            && 0 <= y && y < m;
    }

    void dfs(int x, int y, int sum)
    {
        sum += grid[x][y];
        auto tmp = grid[x][y];
        grid[x][y] = 0;
        res = std::max(res, sum);
        for (auto const& d : dir) {
            auto nx = x + d[0];
            auto ny = y + d[1];
            if (inrange(nx, ny) && grid[nx][ny])
                dfs(nx, ny, sum);
        }
        grid[x][y] = tmp;
    }

    int getMaximumGold(std::vector<std::vector<int>>& grid)
    {
        this->grid = grid;
        n = grid.size();
        m = grid[0].size();
        for (auto i = 0; i < n; i++)
            for (auto j = 0; j < m; j++)
                if (grid[i][j])
                    dfs(i, j, 0);
        return res;
    }
};

