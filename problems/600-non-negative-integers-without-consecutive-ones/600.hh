#pragma once

struct Solution
{
    int a[40];
    // equal
    int g[30][2] = {};
    // less
    int f[30][2] = {};

    int findIntegers(int num)
    {
        auto tmp = num;
        auto n = 0;
        for (; tmp; tmp /= 2)
            a[n++] = tmp & 1;
        g[n - 1][1] = 1;
        f[n - 1][0] = 1;
        for (auto i = n - 2; i >= 0; i--) {
            f[i][0] = f[i + 1][0] + f[i + 1][1];
            f[i][1] = f[i + 1][0];
            if (a[i]) {
                g[i][1] = g[i + 1][0];
                f[i][0] += g[i + 1][1] + g[i + 1][0];
            } else {
                g[i][0] = g[i + 1][0] + g[i + 1][1];
            }
        }
        return f[0][0] + f[0][1] + g[0][0] + g[0][1];
    }
};

