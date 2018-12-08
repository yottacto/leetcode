#pragma once
#include <algorithm>
#include <vector>
#include <unordered_set>

struct Solution
{
    int longestConsecutive(std::vector<int>& nums)
    {
        std::unordered_set<int> all{nums.begin(), nums.end()};
        std::unordered_set<char> vis;
        auto res = 0;
        for (auto i : nums) {
            if (all.count(i - 1) || vis.count(i))
                continue;
            vis.insert(i);
            auto len = 0;
            for (; all.count(i++); len++)
                ;
            res = std::max(res, len);
        }
        return res;
    }
};

