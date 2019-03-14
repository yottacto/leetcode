#pragma once
#include <vector>
#include <string>

struct Solution
{
    int n;
    std::vector<std::string> ans;

    void dfs(int d, std::string const& s, int sum)
    {
        // base condition, if depth reach last char
        if (d == 2 * n) {
            if (!sum)
                ans.emplace_back(s);
            return;
        }
        // pruning, if current sum is negative or too large, just return
        if (sum < 0 || sum > 2 * n - d)
            return;
        dfs(d + 1, s + "(", sum + 1);
        dfs(d + 1, s + ")", sum - 1);
    }

    std::vector<std::string> generateParenthesis(int n)
    {
        this->n = n;
        dfs(0, "", 0);
        return ans;
    }
};

