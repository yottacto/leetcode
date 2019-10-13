#include <vector>

using ll = long long;
auto constexpr mo = 1000000007ll;

struct Solution
{
    ll add(ll x, ll y)
    {
        return (x + y) % mo;
    }

    int dieSimulator(int n, std::vector<int>& rollMax)
    {
        ll f[5001][6][20] = {};
        for (auto i = 0; i < 6; i++)
            f[1][i][0] = f[1][i][1] = 1;
        for (auto i = 2; i <= n; i++) {
            for (auto j = 0; j < 6; j++) {
                for (auto t = 0; t < 6; t++) {
                    if (t == j) continue;
                    f[i][j][1] = add(f[i][j][1], f[i - 1][t][0]);
                }
                f[i][j][0] = add(f[i][j][0], f[i][j][1]);
                for (auto k = 2; k <= std::min(i, rollMax[j]); k++) {
                    f[i][j][k] = f[i - 1][j][k - 1];
                    f[i][j][0] = add(f[i][j][0], f[i][j][k]);
                }
            }
        }
        ll res = 0;
        for (auto i = 0; i < 6; i++)
            res = add(res, f[n][i][0]);
        return res;
    }
};

