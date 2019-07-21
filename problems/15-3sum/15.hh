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
        for (auto it = count.begin(); it != count.end(); ++it) {
            if (it->second >= 2) {
                auto sum = 2 * it->first;
                if (-sum != it->first && count.count(-sum))
                    res.emplace_back(std::initializer_list<int>({
                        it->first, it->first, -sum
                    }));
            }
            for (auto it2 = count.begin(); it2 != count.end(); ++it2) {
                auto sum = it->first + it2->first;
                if (it->first >= it2->first || it2->first >= -sum || !count.count(-sum))
                    continue;
                res.emplace_back(std::initializer_list<int>({
                    it->first, it2->first, -sum
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

