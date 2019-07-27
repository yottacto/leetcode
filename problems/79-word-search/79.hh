#include <vector>
#include <string>
#include <map>
#include <utility>

struct Solution
{
    int l;
    int n;
    int m;
    std::vector<char> vis;
    std::vector<std::vector<int>> dir{
        {-1, 0}, {1, 0},
        {0, -1}, {0, 1},
    };
    std::string word;

    int id(int x, int y)
    {
        return x * m + y;
    }

    auto inrange(int x, int y)
    {
        return (0 <= x && x < n)
            && (0 <= y && y < m);
    }

    template <class T>
    bool dfs(int x, int y, int d, T const& board)
    {
        if (d == l - 1)
            return true;
        vis[id(x, y)] = true;
        for (auto const& di : dir) {
            auto nx = x + di[0];
            auto ny = y + di[1];
            if (inrange(nx, ny) && !vis[id(nx, ny)] && board[nx][ny] == word[d + 1]) {
                if (dfs(nx, ny, d + 1, board)) {
                    vis[id(x, y)] = false;
                    return true;
                }
            }
        }
        vis[id(x, y)] = false;
        return false;
    }

    bool exist(std::vector<std::vector<char>>& board, std::string word)
    {
        n = board.size();
        m = board[0].size();
        l = word.size();
        this->word = word;
        vis.resize(n * m);
        for (auto i = 0; i < n; i++)
            for (auto j = 0; j < m; j++)
                if (word[0] == board[i][j] && dfs(i, j, 0, board))
                    return true;
        return false;
    }
};

