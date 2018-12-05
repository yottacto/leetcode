#pragma once
#include <algorithm>
#include <vector>
#include <queue>

auto constexpr inf = 1 << 30;

struct Solution
{
    int k;
    std::vector<int> next;

    std::vector<int> smallestRange(std::vector<std::vector<int>> const& nums)
    {
        k = nums.size();
        next.resize(k);
        auto cmp = [&](auto a, auto b) {
            return nums[a][next[a]] > nums[b][next[b]];
        };
        auto max = -inf;
        for (auto const& v : nums)
            max = std::max(max, v[0]);
        std::priority_queue<int, std::vector<int>, decltype(cmp)> pq(cmp);
        for (auto i = 0; i < k; i++)
            pq.push(i);
        std::vector<int> res;
        auto len = inf;
        while (true) {
            auto top = pq.top();
            pq.pop();
            auto min = nums[top][next[top]];
            if (max - min < len) {
                len = max - min;
                res = {min, max};
            }
            if (++next[top] >= (int)nums[top].size())
                break;
            max = std::max(max, nums[top][next[top]]);
            pq.push(top);
        }
        return res;
    }
};

