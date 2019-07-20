#include <vector>

struct Solution
{
    int n;
    int m;
    std::vector<std::vector<char>> vis;
    std::vector<std::vector<int>> dir{
        {-1, 0},
        {+1, 0},
        {0, -1},
        {0, +1},
    };

    auto inrange(int x, int y)
    {
        return (0 <= x && x < n)
            && (0 <= y && y < m);
    }

    void dfs(int x, int y, std::vector<std::vector<char>> const& grid)
    {
        vis[x][y] = true;
        for (auto const& d : dir) {
            auto nx = x + d[0];
            auto ny = y + d[1];
            if (!inrange(nx, ny) || vis[nx][ny] || grid[nx][ny] == '0')
                continue;
            dfs(nx, ny, grid);
        }
    }

    int numIslands(std::vector<std::vector<char>>& grid)
    {
        if (grid.empty())
            return {};
        n = grid.size();
        m = grid[0].size();
        vis.resize(n, std::vector<char>(m));
        auto ans = 0;
        for (auto i = 0; i < n; i++)
            for (auto j = 0; j < m; j++)
                if (!vis[i][j] && grid[i][j] == '1') {
                    dfs(i, j, grid);
                    ans++;
                }
        return ans;
    }
};

