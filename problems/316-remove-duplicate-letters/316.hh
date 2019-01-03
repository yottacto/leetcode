#pragma once
#include <string>

struct Solution
{
    int last[30] = {};

    std::string removeDuplicateLetters(std::string s)
    {
        int n = s.size();
        for (auto i = 0; i < n; i++)
            last[s[i] - 'a'] = i;
        auto min = 'z';
        auto pos = -1;
        std::string res;
        for (auto i = 0; i < n; i++) {
            auto ch = s[i];
            if (i > last[ch - 'a']) continue;
            if (ch < min) {
                min = ch;
                pos = i;
            }
            if (i == last[ch - 'a']) {
                res += min;
                last[min - 'a'] = pos;
                min = 'z';
                i = pos;
            }
        }
        return res;
    }
};

