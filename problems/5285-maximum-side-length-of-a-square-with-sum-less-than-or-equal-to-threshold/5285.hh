#include <bits/stdc++.h>

struct Solution
{
    std::vector<std::vector<int>> sum;
    std::vector<std::vector<int>> a;
    int n;
    int m;
    int thres;

    int area(int x, int y, int l)
    {
        return sum[x][y] - sum[x - l][y] - sum[x][y - l] + sum[x - l][y - l];
    }

    bool check(int l)
    {
        for (auto i = l; i <= n; i++)
            for (auto j = l; j <= m; j++)
                if (area(i, j, l) <= thres)
                    return true;
        return false;
    }

    int maxSideLength(std::vector<std::vector<int>>& a, int threshold)
    {
        this->a = a;
        thres = threshold;
        n = a.size();
        m = a[0].size();
        sum.resize(n + 1, std::vector<int>(m + 1));
        for (auto i = 1; i <= n; i++)
            for (auto j = 1; j <= m; j++) {
                sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
                sum[i][j] += a[i - 1][j - 1];
            }
        auto l = 0;
        auto r = std::min(n, m);
        while (l + 1 < r) {
            auto mid = (l + r) / 2;
            if (check(mid))
                l = mid;
            else
                r = mid;
        }
        if (check(r))
            l = r;
        return l;
    }
};

