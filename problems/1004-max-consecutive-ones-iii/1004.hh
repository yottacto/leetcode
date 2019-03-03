#pragma once
#include <algorithm>
#include <iterator>
#include <vector>

struct Solution
{
    int longestOnes(std::vector<int>& a, int k)
    {
        std::vector<int> one;
        std::vector<int> zero;
        auto last = a.begin();
        while (last != a.end()) {
            auto p = std::find(last, a.end(), 1);
            zero.emplace_back(p - last);
            last = std::find(p, a.end(), 0);
            one.emplace_back(last - p);
        }
        int n = one.size();
        auto res = 0;
        auto r = 1;
        auto len = one[0];
        auto sum = 0;
        for (auto l = 0; l < n; l++) {
            if (l == r) {
                len += one[l];
                r++;
            }
            while (r < n && sum + zero[r] <= k) {
                sum += zero[r];
                len += one[r];
                r++;
            }
            auto extra = k - sum;
            auto tmp = len + sum;
            if (r < n) {
                tmp += std::min(extra, zero[r]);
                extra -= std::min(extra, zero[r]);
            }
            tmp += std::min(extra, zero[l]);

            res = std::max(res, tmp);
            len -= one[l];
            if (r > l + 1 && l + 1 < n)
                sum -= zero[l + 1];
        }
        return res;
    }
};

