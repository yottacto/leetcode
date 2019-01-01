#pragma once
#include <algorithm>
#include <vector>
#include <utility>

auto constexpr inf = 1<<30;

struct Solution
{
    int maximumGap(std::vector<int> const& nums)
    {
        int n = nums.size();
        if (n <= 1) return 0;
        auto minmax = std::minmax_element(nums.begin(), nums.end());
        auto bsize = std::max(1, (*minmax.second - *minmax.first) / (n - 1));
        auto nbucket = (*minmax.second - *minmax.first) / bsize + 1;
        std::vector<std::pair<int, int>> buckets(nbucket, {inf, -inf});
        for (auto i : nums) {
            auto ith = (i - *minmax.first) / bsize;
            buckets[ith].first  = std::min(buckets[ith].first, i);
            buckets[ith].second = std::max(buckets[ith].second, i);
        }
        auto res = 0;
        for (auto i = 1; i < nbucket; i++) {
            if (buckets[i].first == inf)
                buckets[i] = buckets[i - 1];
            res = std::max(res, buckets[i].first - buckets[i - 1].second);
        }
        return res;
    }
};

