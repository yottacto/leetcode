#include <vector>

using ll = long long;

struct Solution
{
    ll a;
    ll b;
    ll c;

    ll gcd(ll a, ll b)
    {
        return !b ? a : gcd(b, a % b);
    }

    ll lcm(ll a, ll b)
    {
        return a * b / gcd(a, b);
    }

    ll calc(ll mid)
    {
        return mid / a + mid / b + mid / c
            - mid / lcm(a, b) - mid / lcm(a, c) - mid / lcm(b, c)
             + mid / lcm(lcm(a, b), c);
    }

    int nthUglyNumber(ll n, ll a, ll b, ll c)
    {
        this->a = a;
        this->b = b;
        this->c = c;

        auto l = 1ll;
        auto r = 2000000000ll;
        while (l + 1 < r) {
            auto mid = (l + r) / 2;
            // std::cout << mid << " " << calc(mid) << "\n";
            if (calc(mid) >= n)
                r = mid;
            else
                l = mid;
        }
        if (calc(l) >= n)
            r = l;
        return r;
    }
};

