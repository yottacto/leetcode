#pragma once

auto constexpr mo = 1000000007;

struct Solution
{
    int f[1007];

    int add(int x, int y)
    {
        return (x + y) % mo;
    }

    int sub(int x, int y)
    {
        x = (x - y) % mo;
        return x < 0 ? x + mo : x;
    }

    int kInversePairs(int n, int k)
    {
        f[0] = 1;
        for (auto i = 2; i <= n; i++) {
            for (auto j = k; j >= 1; j--)
                f[j] = sub(f[j], i > j ? 0 : f[j-i]);
            for (auto j = 1; j <= k; j++)
                f[j] = add(f[j], f[j-1]);
        }
        return f[k];
    }
};

