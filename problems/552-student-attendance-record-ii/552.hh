#pragma once

using ll = long long;

auto constexpr maxn = 100'007;
auto constexpr mo   = 1000000007ll;

struct Solution
{
    ll f[maxn][2];

    template <class T>
    ll add(T first)
    {
        return static_cast<ll>(first) % mo;
    }

    template <class T, class... Args>
    ll add(T first, Args... args)
    {
        return (static_cast<ll>(first) + add(args...)) % mo;
    }

    int checkRecord(int n)
    {
        f[1][0] = 2; f[1][1] = 1;
        f[2][0] = 4; f[2][1] = 4;
        f[3][0] = 7; f[3][1] = 12;
        for (auto i = 4; i <= n; i++) {
            f[i][0] = add(f[i - 1][0], f[i - 2][0], f[i - 3][0]);
            f[i][1] = add(
                f[i - 1][1], f[i - 2][1], f[i - 3][1],
                f[i - 1][0], f[i - 2][0], f[i - 3][0]
            );
        }
        return add(f[n][0], f[n][1]);
    }
};

