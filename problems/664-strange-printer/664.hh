#pragma once
#include <algorithm>
#include <string>
#include <cstring>

class Solution
{
    int f[104][104];

    int dp(int l, int r, std::string const& s)
    {
        if (l > r) return 0;
        if (f[l][r] != -1) return f[l][r];
        auto ret = dp(l, r - 1, s) + 1;
        for (int i = l; i < r; i++)
            if (s[i] == s[r])
                ret = std::min(
                    ret,
                    dp(l, i, s) + dp(i + 1, r - 1, s)
                );
        return f[l][r] = ret;
    }

public:
    int strangePrinter(std::string& s)
    {
        s.erase(std::unique(s.begin(), s.end()), s.end());
        int n = s.size();
        if (n == 0) return 0;

        std::memset(f, -1, sizeof(f));

        return dp(0, n - 1, s);
    }
};

