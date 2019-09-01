#include <vector>
#include <numeric>

struct Solution
{
    int dietPlanPerformance(std::vector<int>& calories, int k, int lower, int upper)
    {
        int n = calories.size();
        std::vector<int> sum(n + 1);
        std::partial_sum(calories.begin(), calories.end(), sum.begin() + 1);
        auto res = 0;
        for (auto i = k; i <= n; i++) {
            auto cur = sum[i] - sum[i - k];
            if (cur < lower)
                res--;
            else if (cur > upper)
                res++;
        }
        return res;
    }
};

