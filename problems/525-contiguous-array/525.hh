#include <vector>
#include <unordered_map>

struct Solution
{
    int findMaxLength(std::vector<int>& a)
    {
        int n = a.size();
        auto sum = 0;
        std::unordered_map<int, int> all;
        all[0] = 0;
        auto res = 0;
        for (auto i = 0; i < n; i++) {
            sum += (a[i] == 0 ? -1 : 1);
            if (all.count(sum))
                res = std::max(res, i + 1 - all.at(sum));
            else
                all[sum] = i + 1;
        }
        return res;
    }
};

