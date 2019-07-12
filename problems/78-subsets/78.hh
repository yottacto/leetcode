struct Solution
{
    std::vector<std::vector<int>> subsets(std::vector<int>& nums)
    {
        std::vector<std::vector<int>> res;
        std::vector<int> tmp;
        int n = nums.size();
        for (auto st = 0; st < (1<<n); st++) {
            tmp.clear();
            for (auto i = 0; i < n; i++)
                if (st & (1<<i))
                    tmp.emplace_back(nums[i]);
            res.emplace_back(tmp);
        }
        return res;
    }
};

