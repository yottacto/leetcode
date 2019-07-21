#include <algorithm>
#include <vector>

struct Solution
{
    bool canJump(std::vector<int>& nums)
    {
        int n = nums.size();
        auto max = 0;
        for (auto i = 0; i < n; i++) {
            if (max < i)
                break;
            max = std::max(max, i + nums[i]);
        }
        return max >= n - 1;
    }
};

