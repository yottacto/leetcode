#pragma once
#include <algorithm>
#include <string>

struct Solution
{
    int count[30] = {};

    char next(char& ch)
    {
        return (ch = (ch == 'z' ? 'a' : ch + 1));
    }

    int findSubstringInWraproundString(std::string const p)
    {
        int n = p.size();
        for (auto l = 0, r = 0; l < n; l = r) {
            auto last_ch = p[l];
            r = std::find_if(p.begin() + l + 1, p.end(), [&](char ch) {
                return ch != next(last_ch);
            }) - p.begin();
            auto len = r - l;
            auto ch = p[l];
            for (auto i = 0; i < 26 && len > 0; i++) {
                count[ch-'a'] = std::max(count[ch-'a'], len--);
                next(ch);
            }
        }
        auto ans = 0;
        for (auto i = 0; i < 26; i++)
            ans += count[i];
        return ans;
    }
};

