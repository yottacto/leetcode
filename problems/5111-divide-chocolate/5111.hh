#include <vector>

struct Solution
{
    bool check(int mid, std::vector<int>& a, int k)
    {
        auto res = 0;
        auto sum = 0;
        int n = a.size();
        for (auto i = 0; i < n; i++) {
            sum += a[i];
            if (sum >= mid) {
                sum = 0;
                res++;
            }
        }
        return res >= k + 1;
    }

    int maximizeSweetness(std::vector<int>& a, int k)
    {
        auto l = 1;
        auto r = 0;
        for (auto i : a)
            r += i;
        while (l + 1 < r) {
            auto mid = (l + r) / 2;
            if (check(mid, a, k))
                l = mid;
            else
                r = mid;
        }
        if (check(r, a, k))
            l = r;
        return l;
    }
};

