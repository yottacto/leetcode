#include <vector>
#include <queue>

struct Solution
{
    std::vector<std::vector<char>> vis;
    std::vector<std::vector<int>> grid;
    int n;
    int m;

    std::vector<std::vector<int>> dir{
        {-1, 0},
        {+1, 0},
        {0, -1},
        {0, +1},
    };

    bool inrange(int x, int y)
    {
        return (0 <= x && x < n)
            && (0 <= y && y < m);
    }

    bool bfs(int x, int y)
    {
        std::queue<std::pair<int, int>> q;
        q.emplace(x, y);
        vis[x][y] = true;
        auto cur = true;
        while (!q.empty()) {
            auto [now_x, now_y] = q.front();
            q.pop();
            for (auto const& d : dir) {
                auto next_x = now_x + d[0];
                auto next_y = now_y + d[1];
                if (inrange(next_x, next_y)) {
                    if (grid[next_x][next_y] == 0 && !vis[next_x][next_y]) {
                        q.emplace(next_x, next_y);
                        vis[next_x][next_y] = true;
                    }
                } else {
                    cur = false;
                }
            }
        }
        return cur;
    }

    int closedIsland(std::vector<std::vector<int>>& grid)
    {
        this->grid = grid;
        n = grid.size();
        m = grid[0].size();
        vis.resize(n, std::vector<char>(m));
        auto res = 0;
        for (auto i = 0; i < n; i++)
            for (auto j = 0; j < m; j++) {
                if (grid[i][j] == 0 && !vis[i][j])
                    res += bfs(i, j);
            }
        return res;
    }
};

// [
//     [0,0,1,1,0,1,0,0,1,0],
//     [1,1,0,1,1,0,1,1,1,0],
//     [1,0,1,1,1,0,0,1,1,0],
//     [0,1,1,0,0,0,0,1,0,1],
//     [0,0,0,0,0,0,1,1,1,0],
//     [0,1,0,1,0,1,0,1,1,1],
//     [1,0,1,0,1,1,0,0,0,1],
//     [1,1,1,1,1,1,0,0,0,0],
//     [1,1,1,0,0,1,0,1,0,1],
//     [1,1,1,0,1,1,0,1,1,0]
// ]

