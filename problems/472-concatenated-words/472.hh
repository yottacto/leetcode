#pragma once
#include <algorithm>
#include <unordered_set>
#include <vector>
#include <string>

struct Solution
{
    int n;
    std::vector<std::string> res;
    std::unordered_set<std::string> dict;

    auto concatable(std::string const& word)
    {
        int len = word.size();
        std::vector<char> dp(len + 1);
        dp[0] = true;
        for (auto i = 1; i <= len; i++)
            for (auto j = i; j >= 1; j--) {
                if (dp[j - 1] && dict.count(word.substr(j - 1, i - j + 1))) {
                    dp[i] = true;
                    break;
                }
            }
        return len && dp[len];
    }

    std::vector<std::string> findAllConcatenatedWordsInADict(std::vector<std::string>& words)
    {
        if (words.empty())
            return {};
        n = words.size();
        std::sort(words.begin(), words.end(), [](auto const& a, auto const& b) {
            return a.size() < b.size();
        });
        for (auto i = 0; i < n; i++) {
            if (concatable(words[i]))
                res.emplace_back(words[i]);
            dict.insert(words[i]);
        }
        return res;
    }
};

