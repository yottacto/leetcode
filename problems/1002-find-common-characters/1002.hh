#pragma once
#include <vector>
#include <string>
#include <algorithm>

struct Solution
{
    std::vector<std::string> commonChars(std::vector<std::string>& a)
    {
        std::vector<std::string> res;
        for (auto ch = 'a'; ch <= 'z'; ch++) {
            auto min = 1<<30;
            for (auto const& s : a) {
                auto count = 0;
                for (auto c : s)
                    if (c == ch)
                        count++;
                min = std::min(min, count);
            }
            for (auto i = 0; i < min; i++)
                res.emplace_back(std::string{ch});
        }
        return res;
    }
};

