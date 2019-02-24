#pragma once
#include <vector>

struct Solution
{
    int x, y;

    auto inrange(int x, int l, int r)
    {
        return l <= x && x < r;
    }

    template <class T>
    auto find(T const& board, int dx, int dy)
    {
        auto px = x;
        auto py = y;
        int count{};
        while (inrange(px, 0, 8) && inrange(py, 0, 8)) {
            if (board[px][py] == 'p') {
                count++;
                break;
            }
            if (board[px][py] == 'B')
                break;
            px += dx;
            py += dy;
        }
        return count;
    }

    int numRookCaptures(std::vector<std::vector<char>>& board)
    {
        for (auto i = 0; i < 8; i++)
            for (auto j = 0; j < 8; j++)
                if (board[i][j] == 'R') {
                    x = i;
                    y = j;
                }
        return find(board, -1, 0)
            + find(board, +1, 0)
            + find(board, 0, -1)
            + find(board, 0, +1);
    }
};

