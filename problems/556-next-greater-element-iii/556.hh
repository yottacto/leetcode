#include <vector>
#include <algorithm>
#include <limits>

struct Solution
{
    bool greater(std::vector<int> const& a, std::vector<int> const& b)
    {
        int n = a.size();
        for (auto i = 0; i < n; i++)
            if (a[i] < b[i])
                return false;
            else if (a[i] > b[i])
                return true;
        return false;
    }

    int reduce(std::vector<int> const& a)
    {
        auto inf = convert(std::numeric_limits<int>::max());
        if (a.size() == inf.size() && greater(a, inf))
            return -1;
        int res = 0;
        for (auto i : a)
            res = res * 10 + i;
        return res;
    }

    bool next_permutation(std::vector<int>& a)
    {
        if (a.size() <= 1)
            return false;
        int n = a.size();
        auto i = n - 1;
        for (; i - 1 >= 0 && a[i] <= a[i - 1]; i--)
            ;
        if (!i)
            return false;
        auto j = n - 1;
        for (; j >= 0 && a[j] <= a[i - 1]; j--)
            ;
        std::swap(a[i - 1], a[j]);
        std::reverse(a.begin() + i, a.end());
        return true;
    }

    std::vector<int> convert(int n)
    {
        std::vector<int> a;
        for (auto tn = n; tn; tn /= 10)
            a.emplace_back(tn % 10);
        std::reverse(a.begin(), a.end());
        return a;
    }

    int nextGreaterElement(int n)
    {
        auto a = convert(n);
        if (!next_permutation(a))
            return -1;
        return reduce(a);
    }
};

