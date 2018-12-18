#pragma once
#include <algorithm>
#include <vector>

struct Solution
{
    std::vector<int> kthSmallestPrimeFraction(std::vector<int> a, int k)
    {
        int n = a.size();
        std::sort(a.begin(), a.end());
        auto l = 0.;
        auto r = 1.;
        for (; ; ) {
            auto mid = (l + r) / 2.;
            auto le_count = 0;
            auto p = 0;
            auto q = 1;
            auto j = n - 1;
            for (auto i = 0; i < n; i++) {
                while (j >= 0 && a[j] > mid * a[n - i - 1])
                    j--;
                le_count += j + 1;
                if (j >= 0 && a[j] * q > p * a[n - i - 1]) {
                    p = a[j];
                    q = a[n - i - 1];
                }
            }
            // std::cerr << l << " " << r << " " << mid << " " << le_count << "\n";
            if (le_count > k) {
                r = mid;
            } else if (le_count < k) {
                l = mid;
            } else {
                return {p, q};
            }
        }
        return {-1, -1};
    }
};

