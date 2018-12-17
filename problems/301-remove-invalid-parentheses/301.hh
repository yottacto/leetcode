#pragma once
#include <algorithm>
#include <vector>
#include <string>

struct Solution
{
    void dfs(std::string s, char left, char right, std::vector<std::string>& res, int last_i = 0, int last_j = 0)
    {
        int n = s.size();
        auto sum = 0;
        for (auto i = last_i; i < n; i++) {
            if (s[i] == left)
                sum++;
            else if (s[i] == right)
                sum--;
            if (sum >= 0) continue;
            for (auto j = last_j; j <= i; j++) {
                if (s[j] == right && (j == last_j || s[j - 1] != right))
                    dfs(s.substr(0, j) + s.substr(j + 1), left, right, res, i, j);
            }
            return;
        }
        if (left == '(') {
            std::reverse(s.begin(), s.end());
            dfs(s, right, left, res);
        } else {
            res.emplace_back(s.rbegin(), s.rend());
        }
    }

    std::vector<std::string> removeInvalidParentheses(std::string s)
    {
        std::vector<std::string> res;
        dfs(s, '(', ')', res);
        return res;
    }
};

