#include <vector>
#include <unordered_map>

struct Solution
{
    int findShortestSubArray(std::vector<int>& nums)
    {
        std::unordered_map<int, int> count;
        std::unordered_map<int, int> first;
        int n = nums.size();
        auto max = 0;
        auto res = n;
        for (auto i = 0; i < n; i++) {
            count[nums[i]]++;
            if (!first.count(nums[i]))
                first[nums[i]] = i;
            if (count[nums[i]] > max) {
                max = count[nums[i]];
                res = i - first[nums[i]] + 1;
            } else if (count[nums[i]] == max) {
                res = std::min(res, i - first[nums[i]] + 1);
            }
        }
        return res;
    }
};

