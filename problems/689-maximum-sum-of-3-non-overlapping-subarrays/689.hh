#pragma once
#include <vector>
#include <numeric>

auto constexpr maxn = 20007;

struct Solution
{
    int f[maxn][3] = {};
    int from[maxn][3] = {};
    int n;

    std::vector<int> maxSumOfThreeSubarrays(std::vector<int> const& nums, int k)
    {
        n = nums.size();
        auto sum = nums;
        std::partial_sum(sum.begin(), sum.end(), sum.begin());
        f[k-1][0] = sum[k-1];
        for (auto i = k; i < n; i++) {
            f[i][0] = sum[i] - sum[i-k];
            from[i][0] = i-k+1;
            for (auto j = 0; j < 3; j++) {
                if (j > 0 && f[i-k][j-1]) {
                    f[i][j] = f[i-k][j-1] + sum[i]-sum[i-k];
                    from[i][j] = i-k+1;
                }
                if (f[i-1][j] >= f[i][j]) {
                    f[i][j] = f[i-1][j];
                    from[i][j] = from[i-1][j];
                }
            }
        }
        auto c2 = from[n-1][2];
        auto c1 = from[c2-1][1];
        auto c0 = from[c1-1][0];
        return {c0, c1, c2};
    }
};

