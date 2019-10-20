#include <vector>
#include <algorithm>
#include <string>

struct Solution
{
    bool prefix(std::string const& a, std::string const& b)
    {
        if (a.size() > b.size())
            return false;
        auto l = a.size();
        auto is_prefix = b.substr(0, l) == a;
        if (!is_prefix)
            return false;
        return (b.size() == l || b[l] == '/');
    }

    std::vector<std::string> removeSubfolders(std::vector<std::string>& a)
    {
        int n = a.size();
        std::sort(a.begin(), a.end());
        std::vector<std::string> res;
        res.emplace_back(a[0]);
        auto j = 0;
        for (auto i = 1; i < n; i++) {
            if (!prefix(a[j], a[i])) {
                j = i;
                res.emplace_back(a[i]);
            }
        }
        return res;
    }
};

