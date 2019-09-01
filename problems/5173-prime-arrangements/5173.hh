auto constexpr mo = 1000000007ll;

struct Solution
{
    using ll = long long;

    bool is_prime(int x)
    {
        if (x == 1)
            return false;
        for (auto i = 2; i * i <= x; i++) {
            if (x % i == 0)
                return false;
        }
        return true;
    }

    ll frac(ll x)
    {
        ll res = 1;
        for (auto i = 2; i <= x; i++)
            res = (res * i) % mo;
        return res;
    }

    int numPrimeArrangements(int n)
    {
        auto count = 0;
        for (auto i = 2; i <= n; i++)
            if (is_prime(i))
                count++;
        return (frac(count) * frac(n - count)) % mo;
    }
};

