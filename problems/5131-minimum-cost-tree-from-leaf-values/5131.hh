#include <algorithm>
#include <vector>

auto constexpr inf = 1 << 30;

struct Solution
{
    std::vector<std::vector<int>> f;
    std::vector<std::vector<int>> max;
    std::vector<int> a;

    int dp(int l, int r)
    {
        if (l == r)
            return f[l][r] = 0;
        if (f[l][r] != inf)
            return f[l][r];
        auto res = inf;
        for (auto i = l; i < r; i++) {
            auto left = dp(l, i);
            auto right = dp(i + 1, r);
            res = std::min(res, left + right + max[l][i] * max[i + 1][r]);
        }
        return f[l][r] = res;
    }

    int mctFromLeafValues(std::vector<int>& arr)
    {
        int n = arr.size();
        a = arr;
        f.resize(n + 1, std::vector<int>(n + 1, inf));
        max.resize(n + 1, std::vector<int>(n + 1, -inf));
        for (auto i = 1; i <= n; i++) {
            max[i][i] = a[i - 1];
            for (auto j = i + 1; j <= n; j++)
                max[i][j] = std::max(max[i][j], std::max(max[i][j - 1], a[j - 1]));
        }
        return dp(1, n);
    }
};

