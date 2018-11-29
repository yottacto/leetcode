#pragma once
#include <algorithm>
#include <vector>

struct Solution
{
    void rotate(std::vector<std::vector<int>>& mat)
    {
        int n = mat.size();
        for (auto i = 0; i < (n+1)/2; i++)
            for (auto j = 0; j < n/2; j++) {
                std::swap(mat[i][j], mat[j][n - i - 1]);
                std::swap(mat[i][j], mat[n - i - 1][n - j - 1]);
                std::swap(mat[i][j], mat[n - j - 1][i]);
            }
    }
};

