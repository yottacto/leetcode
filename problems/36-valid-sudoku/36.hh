#include <vector>

struct Solution
{
    bool isValidSudoku(std::vector<std::vector<char>>& board)
    {
        for (auto i = 0; i < 9; i++) {
            auto st = 0;
            for (auto j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                auto num = board[i][j] - '0';
                if (st & (1 << num))
                    return false;
                st |= 1 << num;
            }
        }

        for (auto i = 0; i < 9; i++) {
            auto st = 0;
            for (auto j = 0; j < 9; j++) {
                if (board[j][i] == '.')
                    continue;
                auto num = board[j][i] - '0';
                if (st & (1 << num))
                    return false;
                st |= 1 << num;
            }
        }

        for (auto i = 0, j = 0; i <= 6; ) {
            auto st = 0;
            for (auto x = 0; x < 3; x++)
            for (auto y = 0; y < 3; y++) {
                auto ni = i + x;
                auto nj = j + y;
                if (board[ni][nj] == '.')
                    continue;
                auto num = board[ni][nj] - '0';
                if (st & (1 << num))
                    return false;
                st |= 1 << num;
            }
            i += (j / 6) * 3;
            j = (j + 3) % 9;
        }

        return true;
    }
};

