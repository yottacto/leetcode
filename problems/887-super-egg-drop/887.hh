#include <vector>

auto constexpr inf = 1 << 30;

struct Solution
{
    int log2(int x)
    {
        auto count = 0;
        for (; x; x /= 2)
            count++;
        return count;
    }

    int superEggDrop(int k, int n)
    {
        k = std::min(k, log2(n) + 1);
        std::vector<std::vector<int>> f(k + 1, std::vector<int>(n + 1, inf));
        f[0][0] = 0;
        for (auto i = 1; i <= k; i++) {
            f[i][0] = 0;
            f[i][1] = 1;
        }
        for (auto i = 1; i <= n; i++)
            f[1][i] = i;
        for (auto j = 1; j <= k; j++) {
            auto p = 0;
            for (auto i = 2; i <= n; i++) {
                while (f[j][p] < f[j][i - 1] && f[j][p + 1] < f[j][i - 1])
                    p++;
                if (f[j][p] >= f[j - 1][i - p - 1])
                    f[j][i] = f[j][i - 1];
                else
                    f[j][i] = f[j][i - 1] + 1;
            }
        }
        return f[k][n];
    }
};

