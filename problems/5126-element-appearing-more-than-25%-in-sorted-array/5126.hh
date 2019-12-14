#include <bits/stdc++.h>

struct Solution
{
    int findSpecialInteger(std::vector<int>& a)
    {
        int n = a.size();
        int count = 1;
        for (auto i = 1; i < n; i++) {
            if (a[i] == a[i - 1]) {
                count++;
            } else {
                if (count > n / 4)
                    return a[i - 1];
                count = 1;
            }
        }
        return a[n - 1];
    }
};

