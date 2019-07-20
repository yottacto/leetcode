#include <vector>

struct Solution
{
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target)
    {
        if (matrix.empty())
            return false;
        int n = matrix.size();
        int m = matrix[0].size();
        auto x = 0;
        auto y = m - 1;
        while (x < n && y >= 0) {
            if (matrix[x][y] == target)
                return true;
            if (matrix[x][y] < target)
                x++;
            else
                y--;
        }
        return false;
    }
};

