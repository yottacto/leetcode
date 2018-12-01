#pragma once
#include <string>

using ll = long long;

auto constexpr mo = 1000000007ll;

ll f[1007][1007];

struct Solution
{
    std::string s;

    ll countPalindromicSubsequences(std::string s)
    {
        int n = s.size();
        for (auto i = 0; i < n; i++)
            f[i][i] = 1;

        for (auto len = 2; len <= n; len++) {
            for (auto i = 0; i + len - 1 < n; i++) {
                int l = i;
                int r = i + len - 1;
                if (s[l] != s[r]) {
                    f[l][r] = f[l][r-1] + f[l+1][r] - f[l+1][r-1];
                } else {
                    f[l][r] = f[l+1][r-1] * 2;
                    int tl = l + 1;
                    int tr = r - 1;
                    while (tl <= tr && s[l] != s[tl])
                        tl++;
                    while (tl <= tr && s[l] != s[tr])
                        tr--;
                    if (tl == tr) f[l][r] += 1;
                    else if (tl > tr) f[l][r] += 2;
                    else f[l][r] -= f[tl + 1][tr - 1];
                }
                f[l][r] = ((f[l][r] % mo) + mo) % mo;
            }
        }
        return f[0][n - 1];
    }
};

