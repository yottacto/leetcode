#include <vector>
#include <algorithm>
#include <iterator>

struct _data
{
    int start;
    int end;
    int profit;
};

struct Solution
{
    int jobScheduling(std::vector<int>& startTime, std::vector<int>& endTime, std::vector<int>& profit)
    {
        int n = startTime.size();
        std::vector<_data> a;
        a.reserve(n);
        std::vector<int> all;
        all.emplace_back(0);
        for (auto i = 0; i < n; i++) {
            a.emplace_back(_data{startTime[i], endTime[i], profit[i]});
            all.emplace_back(a[i].end);
        }
        std::sort(all.begin(), all.end());
        all.erase(std::unique(all.begin(), all.end()), all.end());
        std::sort(a.begin(), a.end(), [](auto const& a, auto const& b) {
            return a.end < b.end;
        });
        std::vector<int> dp(all.size());
        auto j = 0u;
        for (auto i = 1u; i < all.size(); i++) {
            dp[i] = dp[i - 1];
            while (j < a.size() && a[j].end == all[i]) {
                auto s = a[j].start;
                auto p = std::prev(std::upper_bound(all.begin(), all.end(), s)) - all.begin();
                dp[i] = std::max(dp[i], dp[p] + a[j].profit);
                j++;
            }
        }
        return dp.back();
    }
};

