#pragma once
#include <algorithm>
#include <iterator>
#include <vector>

class Solution
{
public:
    std::vector<int> plusOne(std::vector<int>& digits)
    {
        if (std::all_of(digits.begin(), digits.end(), [](int i) { return i == 9; }))
            digits.insert(digits.begin(), 0);
        *digits.rbegin() += 1;
        for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
            if (*it < 10) break;
            (*std::next(it))++;
            *it = 0;
        }
        return digits;
    }
};

