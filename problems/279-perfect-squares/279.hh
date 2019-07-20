#include <vector>
#include <algorithm>
#include <cmath>

struct Solution
{
    std::vector<int> f;
    int res;

    int dfs(int n, int count = 0)
    {
        if (!n) {
            res = std::min(res, count);
            return 0;
        }
        if (count + 1 >= res)
            return 1<<30;
        int up = int(std::sqrt(n));
        if (f[n] != -1)
            return f[n];
        auto min = 1<<30;
        for (auto i = up; i >= 1; i--)
            min = std::min(min, dfs(n - i * i, count + 1) + 1);
        return min;
    }

    int numSquares(int n)
    {
        res = n + 1;
        f.reserve(n + 1);
        f.resize(n + 1, -1);
        return dfs(n);
    }
};

