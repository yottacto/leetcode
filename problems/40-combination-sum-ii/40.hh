#pragma once
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <vector>

class Solution
{

public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target)
    {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::set<std::vector<int>>> table(target + 1);
        table[0].insert(std::vector<int>{});
        for (auto i : candidates) {
            if (i > target) break;
            for (auto j = target - i; j >= 0; j--) {
                auto & tmp = table[j];
                for (auto e : tmp) {
                    e.emplace_back(i);
                    table[i + j].insert(e);
                }
            }
        }
        std::vector<std::vector<int>> ans;
        for (auto i : table[target])
            ans.emplace_back(i);
        return ans;
    }
};

