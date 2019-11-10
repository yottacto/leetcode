#include <vector>

struct Solution
{
    int oddCells(int n, int m, std::vector<std::vector<int>>& indices)
    {
        std::vector<std::vector<int>> a(n, std::vector<int>(m));
        for (auto const& v : indices) {
            for (auto i = 0; i < m; i++)
                a[v[0]][i]++;
            for (auto i = 0; i < n; i++)
                a[i][v[1]]++;
        }
        auto res = 0;
        for (auto i = 0; i < n; i++)
            for (auto j = 0; j < m; j++)
                if (a[i][j] & 1)
                    res++;
        return res;
    }
};

