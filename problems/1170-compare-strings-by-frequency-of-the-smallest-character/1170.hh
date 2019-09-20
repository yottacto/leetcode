#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

struct Solution
{
    int calc(std::string const& s)
    {
        std::unordered_map<char, int> count;
        char min = s[0];
        for (auto ch : s) {
            count[ch]++;
            min = std::min(min, ch);
        }
        return count[min];
    }

    std::vector<int> numSmallerByFrequency(std::vector<std::string>& queries, std::vector<std::string>& words)
    {
        std::vector<int> f;
        for (auto const& word : words)
            f.emplace_back(calc(word));
        std::sort(f.begin(), f.end());
        std::vector<int> res;
        int n = words.size();
        for (auto const& s : queries) {
            auto tmpf = calc(s);
            auto it = std::upper_bound(f.begin(), f.end(), tmpf);
            res.emplace_back(n - (it - f.begin()));
        }
        return res;
    }
};

