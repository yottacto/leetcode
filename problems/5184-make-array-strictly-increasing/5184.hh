#include <vector>
#include <algorithm>

auto constexpr inf = 1<<30;

struct Solution
{
    int makeArrayIncreasing(std::vector<int>& a1, std::vector<int>& a2)
    {
        int n = a1.size();
        std::sort(a2.begin(), a2.end());
        a2.erase(std::unique(a2.begin(), a2.end()), a2.end());

        std::vector<std::vector<int>> f(n + 1, std::vector<int>(n + 1, -inf));
        f[0][0] = -1;
        for (auto i = 1; i <= n; i++) {
            if (f[i - 1][0] != -inf && a1[i - 1] > f[i - 1][0])
                f[i][0] = a1[i - 1];
            for (auto j = 1; j <= i; j++) {
                if (f[i - 1][j - 1] != -inf) {
                    auto it = std::upper_bound(a2.begin(), a2.end(), f[i - 1][j - 1]);
                    if (it != a2.end())
                        f[i][j] = *it;
                }
                if (f[i - 1][j] != -inf && a1[i - 1] > f[i - 1][j]) {
                    if (f[i][j] == -inf)
                        f[i][j] = a1[i - 1];
                    else
                        f[i][j] = std::min(f[i][j], a1[i - 1]);
                }
            }
        }

        for (auto i = 0; i <= n; i++)
            if (f[n][i] != -inf)
                return i;
        return -1;
    }
};

