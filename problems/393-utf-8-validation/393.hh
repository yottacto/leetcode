#pragma once
#include <vector>

struct Solution
{
    int get_n(int x)
    {
        auto first_zero = 0;
        for (; first_zero < 8; first_zero++)
            if (!(x & (1<<(7-first_zero))))
                break;
        if (!first_zero)
            return 1;
        if (first_zero == 1 || first_zero > 4)
            return -1;
        return first_zero;
    }

    bool check10(int x)
    {
        if (!(x & (1<<7)))
            return false;
        if (x & (1<<6))
            return false;
        return true;
    }

    bool validUtf8(std::vector<int> const& data)
    {
        int len = data.size();
        for (auto i = 0; i < len; ) {
            int n = get_n(data[i]);
            if (n < 0) return false;
            if (i + n > len) return false;
            for (auto j = 1; j < n; j++)
                if (!check10(data[i + j]))
                    return false;
            i += n;
        }
        return true;
    }
};

