#include <vector>
#include <algorithm>

auto constexpr inf = (1ll) << 42;
auto constexpr mo = 1000000007ll;
using ll = long long;

struct Solution
{
    int kConcatenationMaxSum(std::vector<int>& a, int k)
    {
        int n = a.size();
        std::vector<ll> left(n, -inf);
        std::vector<ll> right(n, -inf);
        left[0] = a[0];
        ll res = std::max(a[0], 0);
        ll sum = a[0];
        for (auto i = 1; i < n; i++) {
            left[i] = std::max<ll>(left[i - 1] + a[i], a[i]);
            res = std::max(res, left[i]);
            sum += a[i];
        }
        right[n - 1] = a[n - 1];
        for (auto i = n - 2; i >= 0; i--)
            right[i] = std::max<ll>(right[i + 1] + a[i], a[i]);
        if (k == 1)
            return res % mo;
        res = std::max(res, right[0] + left[n - 1]);
        if (sum > 0)
            res = std::max(res, (k - 2) * sum + right[0] + left[n - 1]);
        return res % mo;
    }
};

