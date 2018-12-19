#pragma once
#include <algorithm>
#include <vector>

struct Solution
{
    int intersectionSizeTwo(std::vector<std::vector<int>>& inter)
    {
        std::sort(inter.begin(), inter.end(), [](auto const& a, auto const& b) {
            return a[1] < b[1]
                || (a[1] == b[1] && a[0] > b[0]);
        });
        std::vector<int> num;
        for (auto const& i : inter) {
            auto l = std::lower_bound(num.begin(), num.end(), i[0]);
            auto r = std::upper_bound(num.begin(), num.end(), i[1]);
            auto count = r - l;
            if (count >= 2)
                continue;
            if (count == 1) {
                if (*l == i[1])
                    num.emplace_back(i[1] - 1);
                else
                    num.emplace_back(i[1]);
                continue;
            }
            num.emplace_back(i[1] - 1);
            num.emplace_back(i[1]);
            continue;
        }
        return num.size();
    }
};

