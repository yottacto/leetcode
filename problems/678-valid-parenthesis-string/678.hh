#pragma once
#include <string>

struct Solution
{
    bool checkValidString(std::string const& s)
    {
        auto l = 0;
        auto r = 0;
        for (auto ch : s) {
            switch (ch) {
                case '(': l++; r++; break;
                case ')': l--; r--; break;
                default:  l--; r++;
            }
            if (r < 0) return false;
            l = std::max(l, 0);
        }
        return l <= 0 && 0 <= r;
    }
};

