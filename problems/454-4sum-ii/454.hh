#include <vector>
#include <unordered_map>

struct Solution
{
    int fourSumCount(std::vector<int>& a, std::vector<int>& b, std::vector<int>& c, std::vector<int>& d)
    {
        std::unordered_map<int, int> count;
        for (auto i : a)
            for (auto j : b)
                count[i + j]++;
        auto res = 0;
        for (auto i : c)
            for (auto j : d) {
                auto s = i + j;
                if (count.count(-s))
                    res += count.at(-s);
            }
        return res;
    }
};

