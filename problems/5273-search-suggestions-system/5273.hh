#include <vector>
#include <string>
#include <set>

struct Solution
{
    std::vector<std::vector<std::string>> suggestedProducts(std::vector<std::string>& products, std::string s)
    {
        std::multiset<std::string> all;
        for (auto const& s : products)
            all.emplace(s);
        int n = s.size();
        std::vector<std::vector<std::string>> res;
        for (auto i = 0; i < n; i++) {
            for (auto it = all.begin(); it != all.end(); ) {
                auto const& ts = *it;
                if ((int)ts.size() <= i || ts[i] != s[i])
                    it = all.erase(it);
                else
                    ++it;
            }
            auto it = all.begin();
            std::vector<std::string> tmp;
            for (auto i = 0; i < 3 && it != all.end(); i++, ++it)
                tmp.emplace_back(*it);
            res.emplace_back(tmp);
        }
        return res;
    }
};

