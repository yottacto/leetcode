#include <vector>
#include <unordered_map>
#include <iterator>
#include <algorithm>

struct Solution
{
    std::unordered_map<int, int> count;
    std::unordered_map<int, int> occurrence;

    bool check()
    {
        if (occurrence.size() == 1) {
            return occurrence.begin()->first == 1
                || occurrence.begin()->second == 1;
        }
        if (occurrence.size() > 2)
            return false;
        std::pair<int, int> p1 = *occurrence.begin();
        std::pair<int, int> p2 = *std::next(occurrence.begin());
        if (p1.first < p2.first)
            std::swap(p1, p2);
        if ((p2.first == 1 && p2.second == 1) || (p1.second == 1 && p1.first == p2.first + 1))
            return true;
        return false;
    }

    int maxEqualFreq(std::vector<int>& nums)
    {
        int n = nums.size();
        auto res = 1;
        for (auto i = 0; i < n; i++) {
            if (count.count(nums[i])) {
                auto c = count[nums[i]];
                occurrence[c]--;
                if (!occurrence[c])
                    occurrence.erase(c);
                count[nums[i]]++;
                occurrence[count[nums[i]]]++;
            } else {
                count[nums[i]] = 1;
                occurrence[1]++;
            }

            if (check())
                res = i + 1;
        }
        return res;
    }
};

