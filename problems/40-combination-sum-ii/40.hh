#pragma once
#include <algorithm>
#include <vector>

class Solution
{
    std::vector<std::vector<int>> ans;
    std::vector<int> seq;
    int n;

    void find(int deep, int target, std::vector<int>& cand)
    {
        if (!target) {
            ans.emplace_back(seq);
            return;
        }
        if (deep >= n) return;
        for (int i = deep; i < n; i++) {
            if (cand[i] > target) continue;
            seq.emplace_back(cand[i]);
            find(i + 1, target - cand[i], cand);
            seq.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target)
    {
        n = candidates.size();
        std::sort(candidates.begin(), candidates.end());
        find(0, target, candidates);
        std::sort(ans.begin(), ans.end());
        ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};

