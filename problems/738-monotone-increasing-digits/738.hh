#include <vector>
#include <algorithm>

struct Solution
{
    int reduce(std::vector<int> const& a)
    {
        auto res = 0;
        for (auto i : a)
            res = res * 10 + i;
        return res;
    }

    int monotoneIncreasingDigits(int n)
    {
        std::vector<int> a;
        for (auto tn = n; tn; tn /= 10)
            a.emplace_back(tn % 10);
        std::reverse(a.begin(), a.end());
        auto i = 1;
        int l = a.size();
        for (; i < l && a[i - 1] <= a[i]; i++)
            ;
        if (i == l)
            return reduce(a);
        auto j = i - 1;
        for (; j > 0 && a[j] == a[j - 1]; j--)
            ;
        a[j]--;
        for (auto t = j + 1; t < l; t++)
            a[t] = 9;
        return reduce(a);
    }
};

