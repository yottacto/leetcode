#include <vector>
#include <algorithm>

using ll = long long;
auto constexpr mo = 1000000007ll;

struct Solution
{
    int numWays(int n, int l)
    {
        l = std::min(l, (n + 1) / 2 + 1);
        std::vector<std::vector<ll>> f(n + 1, std::vector<ll>(l + 1));

        if (l == 1)
            return 1;

        f[0][0] = 1;
        for (auto i = 1; i <= n; i++) {
            f[i][0] = (f[i - 1][1] + f[i - 1][0]) % mo;
            f[i][l - 1] = (f[i - 1][l - 2] + f[i - 1][l - 1]) % mo;
            for (auto j = 1; j < l - 1; j++)
                f[i][j] = (f[i - 1][j] + f[i - 1][j + 1] + f[i - 1][j - 1]) % mo;
        }
        return f[n][0];
    }

};

