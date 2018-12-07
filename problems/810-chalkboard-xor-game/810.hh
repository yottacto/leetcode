#pragma once
#include <numeric>
#include <vector>
#include <functional>

struct Solution
{
    bool xorGame(std::vector<int>& nums)
    {
        return !std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor<int>{})
            || !(nums.size() & 1);
    }
};

