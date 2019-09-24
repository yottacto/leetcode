#include <vector>
#include <limits>

auto constexpr inf = std::numeric_limits<int>::max();

struct Solution
{
    bool ok(int x1, int x2, int y1, int y2)
    {
        return x1 > x2 && y1 > y2;
    }

    int minSwap(std::vector<int>& a, std::vector<int>& b)
    {
        int n = a.size();
        // f[2 * i] not swap, f[2 * i + 1] swap
        std::vector<int> f(2 * n + 2, inf);
        f[2] = 0;
        f[3] = 1;
        for (auto i = 2; i <= n; i++) {
            if (ok(a[i - 1], a[i - 2], b[i - 1], b[i - 2]))
                f[2 * i] = std::min(f[2 * i], f[2 * (i - 1)]);
            if (ok(a[i - 1], b[i - 2], b[i - 1], a[i - 2]))
                f[2 * i] = std::min(f[2 * i], f[2 * (i - 1) + 1]);
            if (ok(b[i - 1], a[i - 2], a[i - 1], b[i - 2]) && f[2 * (i - 1)] != inf)
                f[2 * i + 1] = std::min(f[2 * i + 1], f[2 * (i - 1)] + 1);
            if (ok(b[i - 1], b[i - 2], a[i - 1], a[i - 2]) && f[2 * (i - 1) + 1] != inf)
                f[2 * i + 1] = std::min(f[2 * i + 1], f[2 * (i - 1) + 1] + 1);
        }
        return std::min(f[2 * n], f[2 * n + 1]);
    }
};

