#include <unordered_set>

struct Solution
{
    std::unordered_set<int> vis;

    bool isHappy(int n)
    {
        if (n == 1)
            return true;
        if (vis.count(n))
            return false;
        vis.emplace(n);
        auto sum = 0;
        for (; n; n /= 10)
            sum += (n % 10) * (n % 10);
        return isHappy(sum);
    }
};

