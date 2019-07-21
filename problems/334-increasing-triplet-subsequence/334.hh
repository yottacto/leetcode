#include <vector>
#include <limits>

struct Solution
{
    bool increasingTriplet(std::vector<int>& nums)
    {
        auto min = std::numeric_limits<int>::max();
        auto mid = std::numeric_limits<int>::max();
        for (auto i : nums) {
            if (i <= min) {
                min = i;
            } else if (i <= mid) {
                mid = i;
            } else {
                return true;
            }
        }
        return false;
    }
};

