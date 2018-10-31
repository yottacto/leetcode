#pragma once

struct Solution
{
    int num(int m, int n, int a)
    {
        int res = 0;
        for (int i = 1; i <= m; ++i)
        {
            if (n * i <= a) res += n;
            else res += a / i;
        }
        return res;
    }

    bool judge(int m, int n, int a, int k)
    {
        int res = 0;
        for (int i = 1; i <= m; ++i) {
            if (n * i <= a) res += n;
            else res += a / i;
            if (res > k) return false;
        }
        return res <= k;
    }

    bool isprim(int m, int n, int a)
    {
        for (int i = 1; i <= m; ++i)
            if (a % i == 0 && a / i <= n)
                return true;
        return false;
    }

    int findKthNumber(int m, int n, int k)
    {
        int left = 1;
        int right = k;
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if (judge(m, n, mid, k)) left = mid;
            else right = mid;
        }

        while (!isprim(m, n, left)) left--;
        while (!isprim(m, n, right)) right++;
        if (num(m, n, left) < k || num(m, n, right) == k) return right;
        return left;
    }
};

