#include <vector>

struct Solution
{
    int findLengthOfLCIS(std::vector<int>& a)
    {
        if (a.empty())
            return 0;
        int n = a.size();
        auto res = 1;
        auto cur = 1;
        for (auto i = 1; i < n; i++) {
            if (a[i] > a[i - 1])
                cur++;
            else
                cur = 1;
            res = std::max(res, cur);
        }
        return res;
    }
};

