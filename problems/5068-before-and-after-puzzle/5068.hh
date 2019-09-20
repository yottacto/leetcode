#include <string>
#include <vector>
#include <algorithm>

struct Solution
{
    std::string first(std::string const& s)
    {
        auto l = s.find(' ');
        if (l == std::string::npos)
            l = s.size();
        return s.substr(0, l);
    }

    std::string last(std::string const& s)
    {
        auto l = s.rfind(' ');
        if (l == std::string::npos)
            return s;
        return s.substr(l + 1);
    }

    std::string concat(std::string const& a, std::string const& b)
    {
        auto res = a;
        auto l = b.find(' ');
        if (l == std::string::npos)
            l = b.size();
        for (auto i = l; i < b.size(); i++)
            res += b[i];
        return res;
    }

    std::vector<std::string> beforeAndAfterPuzzles(std::vector<std::string>& a)
    {
        std::vector<std::string> res;
        int n = a.size();
        for (auto i = 0; i < n; i++)
            for (auto j = 0; j < n; j++)
                if (i != j) {
                    if (last(a[i]) == first(a[j])) {
                        res.emplace_back(concat(a[i], a[j]));
                    }
                }
        std::sort(res.begin(), res.end());
        res.erase(std::unique(res.begin(), res.end()), res.end());
        return res;
    }
};

