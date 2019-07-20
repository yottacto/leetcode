#include <vector>

struct Solution
{
    // case -1: 1 0 1 and 2 1 0, left
    // case  0: 0 1 0, ok
    // case +1: 0 1 2, right
    auto check(int mid, std::vector<int> const& nums)
    {
        int n = nums.size();
        if (!mid) {
            if (mid == n - 1 || nums[1] < nums[0])
                return 0;
            return 1;
        } else if (mid == n - 1) {
            if (!mid || nums[mid - 1] < nums[mid])
                return 0;
            return -1;
        } else {
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return 0;
            if (nums[mid] > nums[mid - 1] && nums[mid] < nums[mid + 1])
                return 1;
            return -1;
        }
    }

    int findPeakElement(std::vector<int>& nums)
    {
        int n = nums.size();
        auto l = 0;
        auto r = n - 1;
        while (l + 1 < r) {
            auto mid = (l + r) / 2;
            auto res = check(mid, nums);
            if (res == 0)
                return mid;
            else if (res < 0)
                r = mid;
            else
                l = mid;
        }
        if (check(l, nums) == 0)
            return l;
        else
            return r;
    }
};

