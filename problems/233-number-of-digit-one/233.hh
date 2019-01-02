#pragma once

struct Solution
{
    int a[30];
    int all[30];
    int calc[30];

    int countDigitOne(int n)
    {
        int len = 0;
        auto count = 0;
        all[0] = 1;
        calc[0] = 0;
        for (; n; n /= 10) {
            a[len++] = n % 10;
            all[len] = all[len - 1] * 10;
            calc[len] = all[len - 1] * len;
        }
        auto one = 0;
        for (auto i = len - 1; i >= 0; i--) {
            if (a[i] > 1) {
                count += a[i] * calc[i] + all[i] + one * a[i] * all[i];
            } else if (a[i] == 1) {
                count += calc[i] + one * all[i];
            }
            one += a[i] == 1;
        }
        count += one;
        return count;
    }
};

