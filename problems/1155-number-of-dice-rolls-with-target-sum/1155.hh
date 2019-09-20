#include <algorithm>

auto constexpr mo = 1000000007ll;

struct Solution
{
    using ll = long long;

    ll dp[50][1010] = {};

    int numRollsToTarget(int d, int f, int target)
    {
        dp[0][0] = 1;
        for (auto i = 1; i <= d; i++) {
            for (auto j = i; j <= std::min(i * f, target); j++) {
                for (auto k = 1; k <= std::min(f, j); k++) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % mo;
                }
            }
        }
        return dp[d][target];
    }
};

