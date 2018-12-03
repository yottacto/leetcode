#pragma once
#include <algorithm>
#include <unordered_set>
#include <string>

struct Solution
{
    int lengthOfLongestSubstring(std::string s)
    {
        int n = s.size();
        auto r = 0;
        std::unordered_set<char> all;
        auto res = 0;
        for (auto l = 0; l < n; l++) {
            while (r < n && !all.count(s[r]))
                all.insert(s[r++]);
            res = std::max(res, r - l);
            all.erase(s[l]);
        }
        return res;
    }
};

