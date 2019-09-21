#include <vector>

struct Solution
{
    int f[2][5007] = {};

    int maxNumberOfApples(std::vector<int>& a)
    {
        int n = a.size();
        auto now = 0;
        auto prev = 1;
        for (auto i = 1; i <= n; i++) {
            std::swap(now, prev);
            for (auto j = 0; j <= 5000; j++) {
                f[now][j] = f[prev][j];
                if (j >= a[i - 1])
                    f[now][j] = std::max(f[now][j], f[prev][j - a[i - 1]] + 1);
            }
        }
        return f[now][5000];
    }
};

