#include <algorithm>
#include <vector>

struct Solution
{
    void setZeroes(std::vector<std::vector<int>>& matrix)
    {
        if (matrix.empty())
            return;
        int n = matrix.size();
        int m = matrix[0].size();
        auto first_row = std::find(matrix[0].begin(), matrix[0].end(), 0) != matrix[0].end();
        for (auto i = 1; i < n; i++)
            for (auto j = 0; j < m; j++) {
                if (matrix[i][j])
                    continue;
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        for (auto i = 1; i < n; i++)
            if (!matrix[i][0])
                std::fill(matrix[i].begin(), matrix[i].end(), 0);
        for (auto j = 0; j < m; j++)
            if (!matrix[0][j])
                for (auto i = 1; i < n; i++)
                    matrix[i][j] = 0;
        if (first_row)
            for (auto j = 0; j < m; j++)
                matrix[0][j] = 0;
    }
};

