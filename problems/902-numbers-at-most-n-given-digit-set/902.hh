#pragma once
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>

struct Solution
{
    int atMostNGivenDigitSet(std::vector<std::string>& d, int n)
    {
        std::vector<int> less_equal(10);
        std::vector<int> digit(10);
        for (auto const& s : d)
            digit[s[0] - '0'] = 1;
        std::partial_sum(digit.begin(), digit.end(), less_equal.begin());
        std::vector<int> a;
        auto tn = n;
        for (; tn; tn /= 10)
            a.emplace_back(tn % 10);
        auto l = 0;
        auto e = 1;
        for (int i = a.size() - 1; i >= 0; i--) {
            l = l * less_equal[9] + e * less_equal[std::max(0, a[i] - 1)] + 1;
            e = e * digit[a[i]];
        }
        return l + e - 1;
    }
};

