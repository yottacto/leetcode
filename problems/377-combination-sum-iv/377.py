class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        n = len(nums)
        f = [0 for i in range(target + 1)]
        f[0] = 1
        for j in range(1, target + 1):
            for i in range(n):
                if j >= nums[i]:
                    f[j] += f[j - nums[i]];
        return f[target]

