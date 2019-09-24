#include <vector>
#include <limits>

auto constexpr inf = std::numeric_limits<int>::max();

struct Solution
{
    int minScoreTriangulation(std::vector<int>& a)
    {
        int n = a.size();
        std::vector<std::vector<int>> f(n, std::vector<int>(n + 1));
        for (auto l = 3; l <= n; l++) {
            for (auto i = 0; i + l - 1 < n; i++)  {
                f[i][l] = inf;
                for (auto k = 2; k < l; k++) {
                    f[i][l] = std::min(f[i][l],
                        a[i] * a[i + k - 1] * a[i + l - 1]
                        + f[i][k]
                        + f[i + k - 1][l - k + 1]
                    );
                }
            }
        }
        return f[0][n];
    }
};

