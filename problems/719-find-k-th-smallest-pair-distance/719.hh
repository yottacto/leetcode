#pragma once
#include <algorithm>
#include <vector>

auto constexpr inf = 1<<30;

struct Solution
{
    int n;

    int smallestDistancePair(std::vector<int>& nums, int k)
    {
        n = nums.size();
        std::sort(nums.begin(), nums.end());
        auto l = 0;
        auto r = 1000000;
        while (l < r) {
            auto mid = (l + r) / 2;
            auto lt = 0;
            auto le = 0;
            auto j = 1;
            auto p = 1;
            for (auto i = 0; i < n - 1; i++) {
                j = std::max(j, i + 1);
                while (j < n && nums[j] - nums[i] < mid)
                    j++;
                lt += j - i - 1;
                p = std::max(p, i + 1);
                while (p < n && nums[p] - nums[i] <= mid)
                    p++;
                le += p - i - 1;
            }
            // std::cout << "[" << l << ", " << r << "], mid=" << mid << " lt=" << lt << " le=" << le << "\n";
            if (lt >= k)
                r = mid - 1;
            else if (le < k)
                l = mid + 1;
            else {
                l = r = mid;
                break;
            }
        }
        auto res = inf;
        auto j = 1;
        for (auto i = 0; i < n - 1; i++) {
            j = std::max(j, i + 1);
            while (j < n && nums[j] - nums[i] < l)
                j++;
            if (j < n)
                res = std::min(res, nums[j] - nums[i]);
        }
        return res;
    }
};

