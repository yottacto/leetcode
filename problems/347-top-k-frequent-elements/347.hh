#pragma once
#include <vector>
#include <unordered_map>

struct Solution
{
    std::vector<int> topKFrequent(std::vector<int>& nums, int k)
    {
        int n = nums.size();
        std::unordered_map<int, int> count;
        for (auto i : nums)
            count[i]++;
        std::vector<std::vector<int>> all(n + 1);
        for (auto const& p : count)
            all[p.second].emplace_back(p.first);
        std::vector<int> res;
        for (auto i = n; i >= 0; i--) {
            for (auto j : all[i])
                res.emplace_back(j);
            if (res.size() > k)
                break;
        }
        res.resize(k);
        return res;
    }
};

