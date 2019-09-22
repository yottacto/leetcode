#include <vector>
#include <algorithm>

auto constexpr inf = 1<<30;

struct Solution
{
    int maxProfit(std::vector<int>& prices, int fee)
    {
        auto buy = -inf;
        auto sell = 0;
        for (auto i : prices) {
            sell = std::max(sell, buy + i);
            buy = std::max(buy, sell - i - fee);
        }
        return sell;
    }
};

