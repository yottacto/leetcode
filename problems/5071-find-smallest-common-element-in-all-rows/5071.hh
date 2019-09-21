#include <vector>

struct Solution
{
    bool check(std::vector<std::vector<int>>& mat, int t)
    {
        int n = mat.size();
        for (auto i = 0; i < n; i++) {
            auto it = std::lower_bound(mat[i].begin(), mat[i].end(), t);
            if (it == mat[i].end())
                return false;
            if (*it != t)
                return false;
        }
        return true;
    }

    int smallestCommonElement(std::vector<std::vector<int>>& mat)
    {
        int m = mat[0].size();
        for (auto i = 0; i < m; i++) {
            auto t = mat[0][i];
            if (check(mat, t))
                return t;
        }
        return -1;
    }
};

