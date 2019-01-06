#pragma once
#include <vector>
#include <algorithm>

struct Solution
{
    std::vector<int> pancakeSort(std::vector<int>& a)
    {
        int n = a.size();
        std::vector<int> res;
        int p = n;
        for (auto i = 0; i < n && p > 1; i++, p--) {
            auto pos = std::max_element(a.begin(), a.begin() + p) - a.begin();
            if (pos != 0) {
                res.emplace_back(pos + 1);
                std::reverse(a.begin(), a.begin() + pos + 1);
            }
            res.emplace_back(p);
            std::reverse(a.begin(), a.begin() + p);
        }
        return res;
    }
};

