#include <vector>
#include <unordered_map>
#include <unordered_set>

struct Solution
{
    int gcd(int x, int y)
    {
        return !y ? x : gcd(y, x % y);
    }

    bool isGoodArray(std::vector<int>& a)
    {
        int n = a.size();
        auto now = a[0];
        for (auto i = 0; i < n; i++)
            now = gcd(now, a[i]);
        return now == 1;
    }
};

