#include <vector>
#include <algorithm>

auto constexpr inf = 1<<30;

struct Solution
{
    int coinChange(std::vector<int>& coins, int amount)
    {
        std::vector<int> f(amount + 1, inf);
        f[0] = 0;
        for (auto c : coins)
            for (auto j = c; j <= amount; j++)
                f[j] = std::min(f[j], f[j - c] + 1);
        return f[amount] == inf ? -1 : f[amount];
    }
};

