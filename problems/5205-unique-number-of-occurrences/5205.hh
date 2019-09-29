#include <vector>
#include <unordered_map>
#include <unordered_set>

struct Solution
{
    bool uniqueOccurrences(std::vector<int>& a)
    {
        std::unordered_map<int, int> count;
        for (auto i : a)
            count[i]++;
        std::unordered_set<int> all;
        for (auto const& p : count) {
            if (all.count(p.second))
                return false;
            all.emplace(p.second);
        }
        return true;
    }
};

