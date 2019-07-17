#include <vector>

struct Solution
{
    void sortColors(std::vector<int>& nums)
    {
        auto n0 = 0;
        auto n1 = 0;
        auto n2 = 0;
        for (auto i = 0u; i < nums.size(); i++) {
            if (nums[i] == 0) {
                std::swap(nums[n0++], nums[i]);
                if (n1 < n0) n1++;
                if (n2 < n0) n2++;
                if (nums[i])
                    i--;
            } else if (nums[i] == 1)  {
                std::swap(nums[n1++], nums[i]);
                if (n2 < n1) n2++;
                if (nums[i] != 1)
                    i--;
            } else if (nums[i] == 2)  {
                std::swap(nums[n2++], nums[i]);
            }
        }
    }
};

