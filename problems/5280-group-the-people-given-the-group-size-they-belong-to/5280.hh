#include <vector>
#include <unordered_map>

struct Solution
{
    std::vector<std::vector<int>> groupThePeople(std::vector<int>& groupSizes)
    {
        std::unordered_map<int, std::vector<std::vector<int>>> all;
        int n = groupSizes.size();
        for (auto i = 0; i < n; i++) {
            auto size = groupSizes[i];
            if (all[size].empty())
                all[size].emplace_back();
            if ((int)all[size].back().size() < size) {
                all[size].back().emplace_back(i);
            } else {
                all[size].emplace_back();
                all[size].back().emplace_back(i);
            }
        }
        std::vector<std::vector<int>> res;
        for (auto const& p : all) {
            for (auto const& g : p.second)
                res.emplace_back(g);
        }
        return res;
    }
};

