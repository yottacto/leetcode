#include <vector>

struct Solution
{
    std::vector<int> numOfBurgers(int t, int c)
    {
        std::vector<int> res;
        if ((t - 2 * c) & 1)
            return {};
        auto x = (t - 2 * c) / 2;
        auto y = c - x;
        if (x < 0 || y < 0)
            return {};
        return {x, y};
    }
};

