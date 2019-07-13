#include <vector>
#include <string>
#include <unordered_map>

struct Solution
{
    using value_type = std::vector<std::vector<std::string>>;

    std::unordered_map<int, value_type> f;

    auto is_palindrome(std::string const& s)
    {
        int l = s.size();
        for (auto i = 0; i < l/2; i++)
            if (s[i] != s[l - i - 1])
                return false;
        return true;
    }

    value_type dfs(std::string const& s)
    {
        int len = s.size();
        if (f.count(len))
            return f.at(len);
        value_type res;
        if (is_palindrome(s)) {
            res.emplace_back(std::vector<std::string>{s});
        }
        for (auto l = 1; l < len; l++) {
            auto sub = s.substr(len - l, l);
            if (is_palindrome(sub)) {
                auto resl = dfs(s.substr(0, len - l));
                for (auto& i : resl) {
                    i.emplace_back(sub);
                    res.emplace_back(i);
                }
            }
        }
        return f[len] = res;
    }

    std::vector<std::vector<std::string>> partition(std::string s)
    {
        return dfs(s);
    }
};

