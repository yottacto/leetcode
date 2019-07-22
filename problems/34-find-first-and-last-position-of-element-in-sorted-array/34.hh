#include <algorithm>
#include <vector>

struct Solution
{
    std::vector<int> searchRange(std::vector<int>& nums, int target)
    {
        auto first = std::lower_bound(nums.begin(), nums.end(), target);
        auto last = std::upper_bound(nums.begin(), nums.end(), target);
        if (first == last)
            return {-1, -1};
        int pfirst = first - nums.begin();
        int plast = last - nums.begin() - 1;
        return {pfirst, plast};
    }
};

