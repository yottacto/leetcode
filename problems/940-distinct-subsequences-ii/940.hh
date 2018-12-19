#pragma once
#include <string>
#include <vector>
#include <unordered_map>

using ll = long long;

auto constexpr mo = 1000000007ll;

auto minus_mo(ll a, ll b)
{
    return (((a-b) % mo) + mo) % mo;
}

struct Solution
{
    int distinctSubseqII(std::string s)
    {
        int n = s.size();
        std::vector<ll> f(n + 1);
        std::unordered_map<char, int> last;
        f[0] = 1;
        for (auto i = 1; i <= n; i++) {
            f[i] = (f[i - 1] * 2) % mo;
            if (last.count(s[i - 1]))
                f[i] = minus_mo(f[i], f[last[s[i - 1]] - 1]);
            last[s[i - 1]] = i;
        }
        return minus_mo(f[n], 1);
    }
};

