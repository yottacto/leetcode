#pragma once
#include <algorithm>
#include <iterator>
#include <vector>
#include <set>
#include <cmath>

using ll = long long;

struct Solution
{
    bool containsNearbyAlmostDuplicate(std::vector<int> const& nums, ll k, ll t)
    {
        if (nums.size() < 2 || k == 0)
            return false;
        int n = nums.size();
        std::multiset<ll> s;
        s.insert(nums[0]);
        for (auto i = 1; i < n; i++) {
            auto it = s.lower_bound(nums[i]);
            if (it != s.end()) {
                if (std::abs(*it - nums[i]) <= t)
                    return true;
            }
            if (it != s.begin()) {
                if (std::abs(*std::prev(it) - nums[i]) <= t)
                    return true;
            }
            s.insert(nums[i]);
            if (i >= k)
                s.erase(s.find(nums[i - k]));
        }
        return false;
    }
};

