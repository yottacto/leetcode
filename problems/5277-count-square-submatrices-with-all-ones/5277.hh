#include <vector>
#include <algorithm>

struct Solution
{
    int countSquares(std::vector<std::vector<int>>& a)
    {
        int n = a.size();
        int m = a[0].size();
        std::vector<std::vector<int>> sum(n + 1, std::vector<int>(m + 1));
        for (auto i = 1; i <= n; i++)
            for (auto j = 1; j <= m; j++)
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1]
                    + a[i - 1][j - 1];
        auto res = 0;
        for (auto i = 1; i <= n; i++)
            for (auto j = 1; j <= m; j++)
                for (auto l = 1; l <= std::min(i, j); l++) {
                    auto ones = sum[i][j] - sum[i - l][j] - sum[i][j - l]
                        + sum[i - l][j - l];
                    if (ones == l * l)
                        res++;
                }
        return res;
    }
};

