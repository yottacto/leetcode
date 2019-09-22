#include <vector>
#include <algorithm>

struct Solution
{
    std::vector<std::vector<int>> minimumAbsDifference(std::vector<int>& a)
    {
        std::vector<std::vector<int>> res;
        std::sort(a.begin(), a.end());
        auto minv = a[1] - a[0];
        int n = a.size();
        for (auto i = 1; i < n; i++)
            minv = std::min(minv, a[i] - a[i - 1]);
        for (auto i = 1; i < n; i++)
            if (a[i] - a[i - 1] == minv)
                res.emplace_back(std::vector<int>{a[i - 1], a[i]});
        return res;
    }
};

