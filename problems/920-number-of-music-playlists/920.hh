// actually, it has an O(nlog(l)) solution (math)
#pragma once
#include <algorithm>

#include <iostream>

using ll = long long;

auto constexpr maxn = 200;
auto constexpr mo = 1000000007ll;

ll add(ll x, ll y) { return (x + y) % mo; }
ll mul(ll x, ll y) { return (x * y) % mo; }

struct Solution
{
    int f[maxn][maxn] = {};

    int numMusicPlaylists(int n, int l, int k)
    {
        f[1][1] = n;
        for (auto i = 1; i <= l; i++) {
            for (auto j = 1; j <= std::min(i, n); j++) {
                if (j >= k + 1)
                    f[i+1][j] = add(f[i+1][j], mul(f[i][j], j - k));
                f[i+1][j+1] = add(f[i+1][j+1], mul(f[i][j], n - j));
            }
        }
        return f[l][n];
    }
};

