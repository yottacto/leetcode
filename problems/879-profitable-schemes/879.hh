#pragma once
#include <vector>
#include <cstring>

using ll = long long;
auto constexpr mo = 1000000007ll;
auto constexpr maxn = 107;

ll f[maxn][maxn][maxn];

ll add(ll x, ll y)
{
    return (x + y) % mo;
}

struct Solution
{
    int profitableSchemes(
        int g,
        int p,
        std::vector<int> const& group,
        std::vector<int> const& profit
    )
    {
        int n = group.size();
        std::memset(f, 0, sizeof(f));

        for (auto k = 0; k <= g; k++)
            f[0][0][k] = 1;
        for (auto i = 1; i <= n; i++) {
            f[i][0][0] = 1;
            for (auto k = 1; k <= g; k++) {
                for (auto j = 0; j <= p; j++) {
                    f[i][j][k] = f[i-1][j][k];
                    if (k < group[i - 1]) continue;
                    f[i][j][k] = add(
                        f[i][j][k],
                        f[i - 1][
                            std::max(0, j - profit[i - 1])
                        ][
                            k - group[i - 1]
                        ]
                    );
                }
            }
        }
        return f[n][p][g];
    }
};

