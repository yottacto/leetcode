#include <vector>

struct NumArray
{
    int n;
    std::vector<int> da;
    std::vector<int> a;

    NumArray(std::vector<int>& a)
        : a(a)
    {
        n = a.size();
        da.resize(n + 1);
        for (auto i = 0; i < n; i++)
            tree_update(i + 1, a[i]);
    }

    int lowbit(int x)
    {
        return x & (-x);
    }

    void tree_update(int i, int d)
    {
        for (; i <= n; i += lowbit(i))
            da[i] += d;
    }

    void update(int i, int val)
    {
        tree_update(i + 1, val - a[i]);
        a[i] = val;
    }

    int prefix_sum(int x)
    {
        auto res = 0;
        for (; x > 0; x -= lowbit(x))
            res += da[x];
        return res;
    }

    int sumRange(int i, int j)
    {
        return prefix_sum(j + 1) - prefix_sum(i);
    }
};

