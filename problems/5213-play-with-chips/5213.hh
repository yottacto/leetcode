#include <vector>
#include <algorithm>

struct Solution
{
    int minCostToMoveChips(std::vector<int>& chips)
    {
        int res[2] = {};
        for (auto i : chips)
            res[i & 1]++;
        return std::min(res[0], res[1]);
    }
};

