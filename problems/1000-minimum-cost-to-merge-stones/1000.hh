#pragma once
#include <vector>

using ll = long long;

auto constexpr maxn = 33;
auto constexpr inf = 1<<30;

struct Solution
{
    ll dp[maxn][maxn][maxn];
    int sum[maxn][maxn] = {};
    int n;

    int mergeStones(std::vector<int>& a, int k)
    {
        n = a.size();
        for (auto i = 0; i < maxn; i++)
            for (auto j = 0; j < maxn; j++)
                for (auto k = 0; k < maxn; k++)
                    dp[i][j][k] = inf;

        for (int i = 1; i <= n; i++) {
            sum[i][i-1] = 0;
            for (int j = i; j <= n;j++) {
                sum[i][j] += sum[i][j-1] + a[j - 1];
                dp[i][j][j-i+1] = 0;
            }
        }

        for (int d = 1; d < n; d++) {
            for (int i = 1; i + d <= n; i++) {
                for (int p = 0; p < d; p++)
                    dp[i][i+d][1] = std::min(dp[i][i+d][1], dp[i][i+p][k-1] + dp[i+p+1][i+d][1] + sum[i][i+d]);

                for (int k = 2; k <= d; k++) {
                    for (int p = 0; p < d; p++)
                        dp[i][i+d][k] = std::min(dp[i][i+d][k], dp[i][i+p][k-1]+dp[i+p+1][i+d][1]);
                }
            }
        }
        if (dp[1][n][1] >= inf)
            return -1;
        else
            return dp[1][n][1];
    }
};

