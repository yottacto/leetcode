#pragma once
#include <algorithm>
#include <string>

struct Solution
{
    int minimum_string_rotation(std::string const& s)
    {
        int i = 0;
        int j = 1;
        int len = s.size();
        for (int k = 0; i < len && j < len && k < len; ) {
            auto cmp = s[(i+k) % len] - s[(j+k) % len];
            if (cmp == 0) {
                k++;
            } else {
                if (cmp > 0)
                    i += k+1;
                else
                    j += k+1;
                if (i == j) j++;
                k = 0;
            }
        }
        return std::min(i, j);
    }

    std::string orderlyQueue(std::string s, int k)
    {
        if (k > 1) {
            std::sort(s.begin(), s.end());
        } else {
            auto p = minimum_string_rotation(s);
            std::rotate(s.begin(), s.begin() + p, s.end());
        }
        return s;
    }
};

