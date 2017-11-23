#pragma once
#include <string>
#include <algorithm>
#include <unordered_map>

class Solution
{
public:
    std::string frequencySort(std::string & s)
    {
        std::unordered_map<char, int> count;
        for (auto ch : s) count[ch]++;
        std::sort(s.begin(), s.end(), [&count](char lhs, char rhs) {
            return count[lhs] > count[rhs]
                || (count[lhs] == count[rhs] && lhs < rhs);
        });
        return s;
    }
};

