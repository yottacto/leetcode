#include <vector>
#include <numeric>
#include <unordered_map>

auto constexpr maxn = 100007;

struct Solution
{
    std::vector<int> primes;
    int np;
    std::vector<int> size;
    std::vector<int> parent;

    Solution()
    {
        init();
    }

    void init()
    {
        std::vector<char> not_prime(maxn);
        for (auto i = 2; i < maxn; i++) {
            if (not_prime[i])
                continue;
            primes.emplace_back(i);
            for (auto j = 2 * i; j < maxn; j += i)
                not_prime[j] = true;
        }
        np = primes.size();
    }

    int get_parent(int x)
    {
        return x == parent[x]
            ? x
            : parent[x] = get_parent(parent[x]);
    }

    void set_union(int x, int y)
    {
        auto tx = get_parent(x);
        auto ty = get_parent(y);
        if (tx != ty) {
            parent[tx] = ty;
            size[ty] += size[tx];
        }
    }

    int find_prime(int x)
    {
        return std::lower_bound(
            primes.begin(),
            primes.end(),
            x
        ) - primes.begin();
    }

    int largestComponentSize(std::vector<int>& a)
    {
        int n = a.size();
        size.resize(np);
        size.resize(np + n, 1);
        parent.resize(np + n);
        std::iota(parent.begin(), parent.end(), 0);

        auto res = 0;
        for (auto i = 0; i < n; i++) {
            auto num = a[i];
            for (auto j = 2; j * j <= num && num > 1; j++)
                if (num % j == 0) {
                    set_union(np + i, find_prime(j));
                    while (num % j == 0)
                        num /= j;
                }
            if (num > 1)
                set_union(np + i, find_prime(num));
        }
        for (auto i = 0; i < np + n; i++)
            res = std::max(res, size[get_parent(i)]);
        return res;
    }
};

