#include <vector>
#include <unordered_map>
#include <iterator>
#include <initializer_list>

struct Solution
{
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
    {
        std::unordered_map<int, int> count;
        for (auto i : nums)
            count[i]++;
        std::vector<std::vector<int>> res;
        std::vector<std::pair<int, int>> all;
        all.resize(count.size());
        auto n = 0;
        for (auto const& p : count)
            all[n++] = p;
        for (auto const& p : all) {
            if (p.second >= 2) {
                auto other = -2 * p.first;
                if (other != p.first && count.count(other))
                    res.emplace_back(std::initializer_list<int>({
                        p.first, p.first, other
                    }));
            }
            for (auto const& p2 : all) {
                auto other = -(p.first + p2.first);
                if (p.first < p2.first && p2.first < other && count.count(other))
                    res.emplace_back(std::initializer_list<int>({
                        p.first, p2.first, other
                    }));
            }
        }
        if (count.count(0) && count.at(0) >= 3)
            res.emplace_back(std::initializer_list<int>({
                0, 0, 0
            }));
        return res;
    }
};

