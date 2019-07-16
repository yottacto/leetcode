#include <vector>
#include <unordered_map>

struct Solution
{
    std::vector<int> majorityElement(std::vector<int>& nums)
    {
        std::unordered_map<int, int> count;
        for (auto i : nums) {
            if (count.count(i) || count.size() < 2)
                count[i]++;
            else {
                for (auto it = count.begin(); it != count.end(); ) {
                    it->second--;
                    if (!it->second)
                        it = count.erase(it);
                    else
                        ++it;
                }
            }
        }
        std::vector<int> res;
        for (auto const& p : count) {
            auto sum = 0;
            for (auto i : nums)
                if (i == p.first)
                    sum++;
            if (sum > (int)(nums.size())/3)
                res.emplace_back(p.first);
        }
        return res;
    }
};

