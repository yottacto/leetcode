#include <vector>

struct Solution
{
    int maxProfit(std::vector<int>& prices)
    {
        if (prices.empty())
            return 0;
        int n = prices.size();
        auto buy = -prices[0];
        auto sell = 0;
        auto sell_cooled = 0;
        for (auto i = 0; i < n; i++) {
            auto tsell = sell;
            sell = std::max(sell, buy + prices[i]);
            buy = std::max(buy, sell_cooled - prices[i]);
            sell_cooled = std::max(sell_cooled, tsell);
        }
        return sell;
    }
};

