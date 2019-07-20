#include <vector>
#include <string>
#include <unordered_map>

struct Solution
{
    std::vector<std::string> table{
        "",
        "",     "abc", "def",
        "ghi",  "jkl", "mno",
        "pqrs", "tuv", "wxyz",
    };

    std::vector<std::string> dfs(int n, std::string const& digits)
    {
        if (!n) return {""};
        auto res = dfs(n - 1, digits);
        decltype(res) ret;
        for (auto ch : table[digits[n - 1] - '0']) {
            ret.reserve(res.size() * table[digits[n - 1] - '0'].size());
            for (auto str : res) {
                str += ch;
                // f[n].emplace_back(std::move(str));
                ret.emplace_back(str);
            }
        }
        return ret;
    }

    std::vector<std::string> letterCombinations(std::string digits)
    {
        if (digits.empty())
            return {};
        int n = digits.size();
        return dfs(n, digits);
    }
};

