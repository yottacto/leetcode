#include <vector>
#include <queue>
#include <utility>

struct Solution
{
    std::vector<std::vector<int>> dir{
        {-1, 0},
        {+1, 0},
        {0, -1},
        {0, +1},
    };

    int n;
    int m;

    int calc_id(int x, int y)
    {
        return x * m + y;
    }

    std::pair<int, int> calc_coord(int id)
    {
        auto x = id / m;
        auto y = id % m;
        return {x, y};
    }

    auto inrange(int x, int y)
    {
        return (0 <= x && x < n)
            && (0 <= y && y < m);
    }

    void solve(std::vector<std::vector<char>>& board)
    {
        if (board.empty() || board[0].empty())
            return;
        n = board.size();
        m = board[0].size();
        std::vector<char> vis(n * m);
        std::queue<int> q;
        // vertical
        for (auto i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                auto id = calc_id(i, 0);
                q.emplace(id);
                vis[id] = true;
            }
            if (board[i][m - 1] == 'O') {
                auto id = calc_id(i, m - 1);
                if (!vis[id]) {
                    q.emplace(id);
                    vis[id] = true;
                }
            }
        }
        // horizontal
        for (auto i = 0; i < m; i++) {
            if (board[0][i] == 'O') {
                auto id = calc_id(0, i);
                if (!vis[id]) {
                    q.emplace(id);
                    vis[id] = true;
                }
            }
            if (board[n - 1][i] == 'O') {
                auto id = calc_id(n - 1, i);
                if (!vis[id]) {
                    q.emplace(id);
                    vis[id] = true;
                }
            }
        }
        while (!q.empty()) {
            auto now = q.front();
            q.pop();
            for (auto const& d : dir) {
                auto [x, y] = calc_coord(now);
                auto nx = x + d[0];
                auto ny = y + d[1];
                auto nid = calc_id(nx, ny);
                if (inrange(nx, ny) && board[nx][ny] == 'O' && !vis[nid]) {
                    q.emplace(nid);
                    vis[nid] = true;
                }
            }
        }
        for (auto i = 0; i < n; i++)
            for (auto j = 0; j < m; j++)
                if (board[i][j] == 'O' && !vis[calc_id(i, j)])
                    board[i][j] = 'X';
    }
};

