#include <vector>

struct Solution
{
    int missingNumber(std::vector<int>& a)
    {
        int n = a.size();
        auto sum = (a[0] + a[n - 1]) * (n + 1) / 2;
        auto tsum = 0;
        for (auto i : a)
            tsum += i;
        return sum - tsum;
    }
};

