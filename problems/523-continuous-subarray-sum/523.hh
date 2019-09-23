#include <vector>
#include <unordered_set>
#include <cmath>

struct Solution
{
    bool checkSubarraySum(std::vector<int>& a, int k)
    {
        int n = a.size();
        if (!k) {
            for (auto i = 1; i < n; i++)
                if (!a[i] && !a[i - 1])
                    return true;
            return false;
        }
        k = std::abs(k);
        std::unordered_set<int> all;
        auto sum = 0;
        auto cache = 0;
        for (auto i : a) {
            sum = (sum + i) % k;
            if (all.count(sum))
                return true;
            all.emplace(cache);
            cache = sum;
        }
        return false;
    }
};

