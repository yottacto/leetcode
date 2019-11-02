#include <vector>

struct Solution
{
    int minimumMoves(std::vector<int>& a)
    {
        int n = a.size();
        int f[n + 1][n + 1];

        for (auto i = 0; i < n; i++)
            f[i][i] = 1;
        for (auto i = 0; i < n - 1; i++) {
            if (a[i] == a[i + 1])
                f[i][i + 1] = 1;
            else
                f[i][i + 1] = 2;
        }
        for (auto l = 3; l <= n; l++) {
            for (auto i = 0; i + l - 1 < n; i++) {
                auto j = i + l - 1;
                f[i][j] = l;
                if (a[i] == a[j])
                    f[i][j] = f[i + 1][j - 1];
                for (auto k = i; k < j; k++) {
                    f[i][j] = std::min(
                        f[i][j],
                        f[i][k] + f[k + 1][j]
                    );
                }
            }
        }
        return f[0][n - 1];
    }
};

