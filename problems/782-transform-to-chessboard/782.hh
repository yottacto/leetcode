#pragma once
#include <algorithm>
#include <cmath>
#include <vector>

struct Solution
{
    int n;
    int m;

    int calc(std::vector<int> const& v)
    {
        int n = v.size();
        auto swap0 = 0;
        auto swap1 = 0;
        auto count0 = 0;
        auto count1 = 0;
        for (auto i = 0; i < n; i++) {
            swap0 += v[i] != (i&1);
            swap1 += v[i] != !(i&1);
            count0 += v[i] == 0;
            count1 += v[i] == 1;
        }
        if (n & 1) {
            if (abs(count0 - count1) != 1)
                return -1;
            return swap0 & 1 ? swap1/2 : swap0/2;
        }
        if (count0 != count1)
            return -1;
        return std::min(swap0, swap1) / 2;
    }

    int movesToChessboard(std::vector<std::vector<int>>& board)
    {
        n = board.size();
        m = board[0].size();
        for (auto i = 0; i < n; i++)
            for (auto j = 0; j < m; j++)
                if (board[i][j] ^ board[0][0] ^ board[i][0] ^ board[0][j])
                    return -1;
        auto row_swap = calc(board[0]);
        if (row_swap < 0)
            return -1;
        std::vector<int> col;
        col.reserve(n);
        for (auto const& v : board)
            col.emplace_back(v[0]);
        auto col_swap = calc(col);
        if (col_swap < 0)
            return -1;
        return row_swap + col_swap;
    }
};

