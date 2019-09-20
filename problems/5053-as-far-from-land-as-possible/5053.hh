#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>

struct Solution
{
    std::vector<std::vector<int>> dir{
        {-1, 0}, {1, 0},
        {0, -1}, {0, 1},
    };

    bool inrange(int x, int y, int n, int m)
    {
        return (0 <= x && x < n)
            && (0 <= y && y < m);
    }

    int maxDistance(std::vector<std::vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        std::queue<std::pair<int, int>> q;
        std::vector<std::vector<int>> dis(n, std::vector<int>(m));
        for (auto i = 0; i < n; i++)
            for (auto j = 0; j < m; j++)
                if (grid[i][j] == 1) {
                    q.emplace(i, j);
                    dis[i][j] = 0;
                }
        auto res = -1;
        while (!q.empty()) {
            auto now = q.front();
            q.pop();
            for (auto const& d : dir) {
                auto nx = now.first + d[0];
                auto ny = now.second + d[1];
                if (inrange(nx, ny, n, m) && !grid[nx][ny] && !dis[nx][ny]) {
                    dis[nx][ny] = dis[now.first][now.second] + 1;
                    res = std::max(res, dis[nx][ny]);
                    q.emplace(nx, ny);
                }
            }
        }

        return res;
    }
};

