#pragma once
#include <vector>
#include <algorithm>

namespace util
{

template <class T>
T min(T a, T b)
{
    return std::min(a, b);
}

template <class T, class... U>
T min(T a, T b, U... args)
{
    return min(min(a, b), args...);
}

} // namespace

struct Solution
{
    int left[501][501];
    int right[501][501];
    int up[501][501];
    int down[501][501];
    int board[501][501];
    int res{};

    int orderOfLargestPlusSign(int n, std::vector<std::vector<int>>& mines)
    {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                board[i][j] = 1;

        for (auto const& v : mines)
            board[v[0]][v[1]] = 0;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                left[i][j] = board[i][j];
                if (left[i][j] && j)
                    left[i][j] += left[i][j - 1];

                up[i][j] = board[i][j];
                if (up[i][j] && i)
                    up[i][j] += up[i-1][j];
            }

        for (int i = n - 1; i >= 0; --i)
            for (int j = n - 1; j >= 0; --j) {
                right[i][j] = board[i][j];
                if (right[i][j] && j != n - 1)
                    right[i][j] += right[i][j + 1];

                down[i][j] = board[i][j];
                if (down[i][j] && i != n - 1)
                    down[i][j] += down[i+1][j];

                res = std::max(res, util::min(left[i][j], right[i][j], up[i][j], down[i][j]));
            }
        return res;
    }
};

