#include <vector>
#include <unordered_map>

struct Solution
{
    int numberOfSubarrays(std::vector<int>& a, int k)
    {
        int n = a.size();
        auto sum = 0;
        auto res = 0;
        std::unordered_map<int, int> count;
        count[0] = 1;
        for (auto i = 0; i < n; i++) {
            if (a[i] & 1)
                sum++;
            count[sum]++;
            if (sum < k)
                continue;
            auto t = sum - k;
            if (count.count(t))
                res += count.at(t);
        }
        return res;
    }
};

