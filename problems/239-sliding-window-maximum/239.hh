#pragma once
#include <vector>
#include <deque>

struct Solution
{
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k)
    {
        int n = nums.size();
        std::deque<int> dq;
        std::vector<int> res;
        for (auto i = 0; i < n; i++) {
            while (!dq.empty() && nums[i] >= nums[dq.back()])
                dq.pop_back();
            dq.emplace_back(i);
            while (i - dq.front() >= k)
                dq.pop_front();
            if (i >= k - 1)
                res.emplace_back(nums[dq.front()]);
        }
        return res;
    }
};

