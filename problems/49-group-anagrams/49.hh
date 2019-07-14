#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

struct Solution
{
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs)
    {
        std::unordered_map<std::string, std::vector<std::string>> all;
        for (auto const& s : strs) {
            auto ts = s;
            std::sort(ts.begin(), ts.end());
            all[ts].emplace_back(s);
        }
        std::vector<std::vector<std::string>> res;
        for (auto const& p : all)
            res.emplace_back(p.second);
        return res;
    }
};

