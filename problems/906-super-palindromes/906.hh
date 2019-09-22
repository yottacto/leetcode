#include <string>
#include <algorithm>

using ll = long long;

struct Solution
{
    ll palindrome_odd(ll x, ll mid)
    {
        auto s = std::to_string(x);
        auto ts = s;
        std::reverse(ts.begin(), ts.end());
        s += char(mid + '0') + ts;
        return std::stoll(s);
    }

    ll palindrome_even(ll x)
    {
        auto s = std::to_string(x);
        auto ts = s;
        std::reverse(ts.begin(), ts.end());
        s += ts;
        return std::stoll(s);
    }

    auto check(ll x)
    {
        auto s = std::to_string(x);
        int l = s.size();
        for (auto i = 0; i < l/2; i++)
            if (s[i] != s[l - i - 1])
                return false;
        return true;
    }

    ll calc(ll n)
    {
        if (!n)
            return 0;
        if (n < 4)
            return 1;
        if (n < 9)
            return 2;
        if (n <= 10)
            return 3;
        auto tot = 3ll;
        auto start = 1ll;
        auto end = 10ll;
        for (auto l = 1; l <= 4; l++) {
            for (auto i = start; i < end; i++) {
                auto t = palindrome_even(i);
                if (t * t > n)
                    return tot;
                if (check(t * t))
                    tot++;
            }
            for (auto i = start; i < end; i++) {
                for (auto j = 0; j < 10; j++) {
                    auto t = palindrome_odd(i, j);
                    if (t * t > n)
                        return tot;
                    if (check(t * t))
                        tot++;
                }
            }
            start *= 10;
            end *= 10;
        }
        return tot;
    }

    int superpalindromesInRange(std::string l, std::string r)
    {
        auto nl = std::stoll(l);
        auto nr = std::stoll(r);
        return calc(nr) - calc(nl - 1);
    }
};

