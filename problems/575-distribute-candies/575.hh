#include <unordered_set>
#include <vector>

struct Solution
{
    int distributeCandies(std::vector<int>& candies)
    {
        std::unordered_set<int> all{candies.begin(), candies.end()};
        int n = candies.size();
        int tot = all.size();
        if (tot >= n / 2)
            return n / 2;
        else
            return tot;
    }
};

