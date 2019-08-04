#include <algorithm>
#include <vector>

auto constexpr inf = 1<<30;

struct Solution
{
    int n;
    std::vector<int> a;

    int get_prev(int i)
    {
        if (!i)
            return inf;
        return a[i - 1];
    }

    int get_next(int i)
    {
        if (i == n - 1)
            return inf;
        return a[i + 1];
    }

    int calc(int start)
    {
        auto res = 0;
        for (auto i = start; i < n; i += 2) {
            auto prev = get_prev(i);
            auto next = get_next(i);
            auto min = std::min(prev, next);
            if (a[i] >= min)
                res += a[i] - min + 1;
        }
        return res;
    }

    int movesToMakeZigzag(std::vector<int>& nums)
    {
        n = nums.size();
        a = nums;
        return std::min(calc(0), calc(1));
    }
};

