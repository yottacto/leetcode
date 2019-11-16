#include <algorithm>
#include <vector>
#include <string>

using ll = long long;
auto constexpr mo = 1000000007ll;

struct Solution
{
    std::vector<ll> f;
    int n;

    ll dp(ll n)
    {
        if (n & 1)
            return 0;
        if (n <= 2)
            return 1;
        if (f[n] != -1)
            return f[n];
        f[n] = 0;
        for (auto i = 2; i <= n; i += 2) {
            f[n] += dp(i - 2) * dp(n - i);
            f[n] %= mo;
        }
        f[n] %= mo;
        return f[n];
    }

    int numberOfWays(int n)
    {
        this->n = n;
        f.resize(n + 1, -1);
        f[0] = 1;
        f[2] = 1;
        return dp(n);
    }
};

