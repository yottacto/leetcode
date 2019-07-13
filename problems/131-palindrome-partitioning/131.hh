#include <vector>
#include <string>
#include <unordered_map>

struct Solution
{
    using value_type = std::vector<std::vector<std::string>>;

    std::vector<value_type> f;

    auto is_palindrome(std::string const& s)
    {
        int l = s.size();
        for (auto i = 0; i < l/2; i++)
            if (s[i] != s[l - i - 1])
                return false;
        return true;
    }

    void dfs(std::string const& s)
    {
        int len = s.size();
        if (!f[len].empty())
            return;
        value_type res;
        if (is_palindrome(s))
            res.emplace_back(std::vector<std::string>{s});
        for (auto l = 1; l < len; l++) {
            auto sub = s.substr(len - l, l);
            if (is_palindrome(sub)) {
                dfs(s.substr(0, len - l));
                for (auto const& i : f[len - l]) {
                    res.emplace_back(i);
                    res.back().emplace_back(sub);
                }
            }
        }
        f[len] = std::move(res);
    }

    std::vector<std::vector<std::string>> partition(std::string s)
    {
        f.resize(s.size() + 1);
        dfs(s);
        return f[s.size()];
    }
};

