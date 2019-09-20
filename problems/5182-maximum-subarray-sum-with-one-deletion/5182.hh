#include <vector>

auto constexpr inf = 1<<29;

struct Solution
{
    int maximumSum(std::vector<int>& a)
    {
        int n = a.size();
        std::vector<int> left(n + 2);
        std::vector<int> right(n + 2);
        left[0] = right[n + 1] = -inf;
        for (auto i = 1; i <= n; i++)
            left[i] = std::max(a[i - 1], a[i - 1] + left[i - 1]);
        for (auto i = n; i >= 1; i--)
            right[i] = std::max(a[i - 1], a[i - 1] + right[i + 1]);

        auto res = -inf;
        for (auto i = 1; i <= n; i++) {
            res = std::max(
                std::max(
                    res,
                    std::max(a[i - 1], a[i - 1] + left[i - 1] + right[i + 1])
                ),
                std::max(
                    std::max(a[i - 1] + left[i - 1], a[i - 1] + right[i + 1]),
                    std::max(left[i - 1], right[i + 1])
                )
            );
            res = std::max(res, left[i - 1] + right[i + 1]);
        }
        return res;
    }
};

