#pragma once
#include <algorithm>
#include <vector>

struct Solution
{
    int n;
    int dp[600][600] = {};

    int maxCoins(std::vector<int>& nums)
    {
        nums.insert(nums.begin(), 1);
        nums.emplace_back(1);
        n = nums.size();

        for (auto l = 2; l < n; l++) {
            for (auto left = 0; left + l < n; left++) {
                auto right = left + l;
                for (auto i = left + 1; i < right; i++) {
                    dp[left][right] = std::max(dp[left][right],
                        dp[left][i] + dp[i][right]
                            + nums[i] * nums[left] * nums[right]
                    );
                }
            }
        }

        return dp[0][n-1];
    }
};

