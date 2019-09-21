#include <vector>
#include <algorithm>

using ll = long long;

struct Solution
{
    int maxRotateFunction(std::vector<int>& a)
    {
        int n = a.size();
        ll cur = 0;
        ll sum = 0;
        for (auto i = 0; i < n; i++) {
            cur += i * a[i];
            sum += a[i];
        }
        ll res = cur;
        for (auto i = 1; i < n; i++) {
            cur += sum - static_cast<ll>(n) * a[n - i];
            res = std::max(res, cur);
        }
        return res;
    }
};

