#include <vector>
#include <algorithm>

using ll = long long;

struct Solution
{
    std::vector<int> a;

    ll calc_sum(ll mid)
    {
        ll sum{};
        for (auto i : a)
            sum += (i + mid - 1) / mid;
        return sum;
    }

    int smallestDivisor(std::vector<int>& nums, ll threshold)
    {
        a = nums;
        ll l = 1;
        ll r = *std::max_element(nums.begin(), nums.end()) + 1;
        while (l + 1 < r) {
            auto mid = (l + r) / 2;
            if (calc_sum(mid) > threshold)
                l = mid;
            else
                r = mid;
        }
        if (calc_sum(l) <= threshold)
            r = l;
        return r;
    }
};

