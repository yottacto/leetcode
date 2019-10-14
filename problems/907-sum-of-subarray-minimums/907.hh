#include <vector>
#include <stack>

using ll = long long;
auto constexpr mo = 1000000007ll;

struct Solution
{
    int sumSubarrayMins(std::vector<int>& a)
    {
        int n = a.size() + 1;
        a.insert(a.begin(), -1);
        a.emplace_back(0);
        std::stack<int> q;
        q.emplace(0);
        std::vector<int> d_left(n + 1);
        auto res = 0ll;
        for (auto i = 1; i <= n; i++) {
            while (!q.empty() && a[i] <= a[q.top()]) {
                res += (a[q.top()] * d_left[q.top()] * (i - q.top())) % mo;
                res %= mo;
                q.pop();
            }
            d_left[i] = i - q.top();
            q.emplace(i);
        }
        return res;
    }
};

