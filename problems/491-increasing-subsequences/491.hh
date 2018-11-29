#pragma once
#include <vector>
#include <algorithm>

struct Solution
{
    template <class Vec>
    void unique(Vec& v)
    {
        std::sort(v.begin(), v.end());
        v.erase(std::unique(v.begin(), v.end()), v.end());
    }

    std::vector<std::vector<int>> findSubsequences(std::vector<int>& nums)
    {
        int n = nums.size();
        std::vector<std::vector<std::vector<int>>> seq;
        seq.reserve(n);
        for (auto i = 0; i < n; i++)
            seq.emplace_back(std::vector<std::vector<int>>{{nums[i]}});
        std::vector<std::vector<int>> res;
        for (auto i = 0; i < n; i++) {
            for (auto j = 0; j < i; j++) {
                if (nums[i] >= nums[j])
                    for (auto v : seq[j]) {
                        v.emplace_back(nums[i]);
                        seq[i].emplace_back(v);
                        res.emplace_back(v);
                    }
            }
            unique(seq[i]);
        }
        unique(res);
        return res;
    }
};

