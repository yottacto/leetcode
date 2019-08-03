#include <algorithm>
#include <vector>
#include <numeric>

auto constexpr inf = 1<<30;

struct Solution
{
    int n;
    std::vector<std::vector<int>> f;
    std::vector<int> sum;

    int dp(int i, int m)
    {
        if (f[i][m] != -inf)
            return f[i][m];
        if (i == n)
            return 0;
        auto res = -inf;
        for (auto x = 1; x <= std::min(2 * m, n - i); x++) {
            auto tmp = dp(i + x, std::max(m, x));
            res = std::max(res, sum[n] - sum[i] - tmp);
        }
        return f[i][m] = res;
    }

    int stoneGameII(std::vector<int>& piles)
    {
        n = piles.size();
        f.resize(n + 1, std::vector<int>(n + 1, -inf));
        sum.resize(n + 1);
        std::partial_sum(piles.begin(), piles.end(), sum.begin() + 1);
        return dp(0, 1);
    }
};

