#include <vector>

struct Solution
{
    int findDuplicate(std::vector<int>& nums)
    {
        int n = nums.size() - 1;
        auto slow = nums[n];
        auto fast = nums[n];
        do {
            slow = nums[slow - 1];
            fast = nums[nums[fast - 1] - 1];
        } while (slow != fast);

        auto res = nums[n];
        while (res != slow) {
            slow = nums[slow - 1];
            res = nums[res - 1];
        }
        return res;
    }
};

