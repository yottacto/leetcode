#include <algorithm>
#include <vector>
#include <map>

struct Solution
{
    int numEquivDominoPairs(std::vector<std::vector<int>>& dominoes)
    {
        std::map<std::vector<int>, int> count;
        for (auto v : dominoes) {
            if (v[0] > v[1])
                std::swap(v[0], v[1]);
            count[v]++;
        }
        auto ans = 0;
        for (auto const& p : count)
            ans += p.second * (p.second - 1) / 2;
        return ans;
    }
};

