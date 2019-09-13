#include <string>
#include <vector>

auto constexpr mo = 1000000007ll;

struct Solution
{
    using ll = long long;

    ll add(ll a, ll b)
    {
        return (a + b) % mo;
    }

    ll mul(ll a, ll b)
    {
        return (a * b) % mo;
    }

    int numDecodings(std::string s)
    {
        int n = s.size();
        std::vector<ll> f(n + 1);
        f[0] = 1;
        if (s[0] == '*')
            f[1] = 9;
        else if (s[0] == '0')
            f[1] = 0;
        else
            f[1] = 1;
        for (auto i = 2; i <= n; i++) {
            if (s[i - 1] == '*') {
                f[i] = mul(9, f[i - 1]);
                if (s[i - 2] == '*') {
                    f[i] = add(f[i], mul(f[i - 2], 15));
                } else if (s[i - 2] == '1') {
                    f[i] = add(f[i], mul(f[i - 2], 9));
                } else if (s[i - 2] == '2') {
                    f[i] = add(f[i], mul(f[i - 2], 6));
                }
            } else {
                auto v = s[i - 1] - '0';
                if (v)
                    f[i] = f[i - 1];
                if (s[i - 2] == '*') {
                    if (v <= 6)
                        f[i] = add(f[i], mul(f[i - 2], 2));
                    else
                        f[i] = add(f[i], mul(f[i - 2], 1));
                } else if (s[i - 2] == '1') {
                    f[i] = add(f[i], mul(f[i - 2], 1));
                } else if (s[i - 2] == '2') {
                    if (v <= 6)
                        f[i] = add(f[i], mul(f[i - 2], 1));
                }
            }
        }
        return f[n];
    }
};

