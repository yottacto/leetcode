#pragma once
#include <vector>

struct Solution
{
    int n;
    int m;
    int sum[303][303] = {0};

    int calc(std::vector<int> const& a, int l, int r, int target)
    {
        if (l == r) {
            return target == a[l];
        }
        int mid = (l + r) / 2;
        auto res = calc(a, l, mid, target) + calc(a, mid + 1, r, target);
        std::map<int, int> cc;
        auto s = 0;
        for (auto i = mid; i >= l; i--) {
            s += a[i];
            cc[s]++;
        }
        s = 0;
        for (auto i = mid + 1; i <= r; i++) {
            s += a[i];
            auto t = target - s;
            if (cc.count(t))
                res += cc[t];
        }
        return res;
    }

    int numSubmatrixSumTarget(std::vector<std::vector<int>>& matrix, int target)
    {
        n = matrix.size();
        m = matrix[0].size();
        for (auto i = 0; i < n; i++)
        for (auto j = 0; j < m; j++) {
            sum[i + 1][j + 1] = matrix[i][j] + sum[i][j + 1] + sum[i + 1][j]
                - sum[i][j];
        }

        auto count = 0;
        std::vector<int> a(n);
        for (auto y = 0; y < m; y++)
            for (auto y2 = y; y2 < m; y2++) {
                for (auto i = 0; i < n; i++)
                    a[i] = sum[i + 1][y2 + 1] - sum[i + 1][y] - sum[i][y2 + 1] + sum[i][y];
                auto tmp = calc(a, 0, n - 1, target);
                // for (auto i : a)
                //     std::cout << i << " ";
                // std::cout << "  = " << tmp << "\n";
                count += tmp;
            }

        return count;
    }
};

