#include <vector>

struct Solution
{
    int n;
    int m;

    std::vector<std::vector<int>> dir{
        {0, +1}, {+1, 0},
        {0, -1}, {-1, 0},
    };

    auto inrange(int x, int y)
    {
        return (0 <= x && x < n)
            && (0 <= y && y < m);
    }

    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix)
    {
        if (matrix.empty())
            return {};
        n = matrix.size();
        m = matrix[0].size();
        std::vector<std::vector<char>> vis(n, std::vector<char>(m));
        std::vector<int> res;
        int d = 0;
        int x = 0;
        int y = 0;
        for (auto i = 0; i < n * m; i++) {
            res.emplace_back(matrix[x][y]);
            vis[x][y] = true;
            for (auto j = 0; j < 4; j++) {
                auto nx = x + dir[d][0];
                auto ny = y + dir[d][1];
                if (!inrange(nx, ny) || vis[nx][ny]) {
                    d = (d + 1) % 4;
                    continue;
                }
                x = nx;
                y = ny;
                break;
            }
        }
        return res;
    }
};

