#include <algorithm>
#include <vector>
#include <numeric>
#include <utility>

struct Solution
{
    int longestWPI(std::vector<int>& hours)
    {
        // sum[r] - sum[l-1] > (r - l + 1) / 2
        // 2 sum[r] - r > 2 sum[l-1] - (l-1)

        int n = hours.size();
        for (auto& i : hours)
            i = i > 8;
        std::vector<int> sum(n + 1);
        std::partial_sum(hours.begin(), hours.end(), sum.begin() + 1);
        for (auto i = 0; i <= n; i++)
            sum[i] = 2 * sum[i] - i;

        std::vector<std::pair<int, int>> a(n + 1);
        for (auto i = 0; i <= n; i++)
            a[i] = std::make_pair(i, sum[i]);
        std::sort(a.begin(), a.end(), [](auto const& a, auto const& b) {
            return a.second < b.second
                || (a.second ==  b.second && a.first > b.first);
        });
        auto left = n + 1;
        auto res = 0;

        for (auto const& i : a) {
            res = std::max(res, i.first - left);
            left = std::min(left, i.first);
        }
        return res;
    }
};

