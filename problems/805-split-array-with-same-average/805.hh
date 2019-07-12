#pragma once
#include <vector>
#include <utility>
#include <unordered_set>
#include <numeric>
#include <algorithm>

struct Solution
{
    auto encode(int count, int sum)
    {
        return sum * 100 + count;
    }

    bool splitArraySameAverage(std::vector<int>& a)
    {
        auto all_sum = std::accumulate(a.begin(), a.end(), 0);

        int n = a.size();
        std::vector<int> b(a.begin() + n/2, a.end());
        n /= 2;
        int m = b.size();
        std::unordered_set<int> s;
        for (auto i = 0; i < (1<<n); i++) {
            auto sum = 0;
            auto count = 0;
            for (auto j = 0; j < n; j++) {
                if (i & (1<<j)) {
                    count++;
                    sum += a[j];
                }
            }
            s.emplace(encode(count, sum));
        }

        for (auto i = 0; i < (1<<m); i++) {
            auto sum = 0;
            auto count = 0;
            for (auto j = 0; j < m; j++) {
                if (i & (1<<j)) {
                    count++;
                    sum += b[j];
                }
            }
            for (auto tot = std::max(1, count); tot < n + m; tot++) {
                if (((all_sum * tot) % (n + m)) != 0)
                    continue;
                auto tmp = (all_sum * tot) / (n + m);
                if (tmp < sum)
                    continue;
                auto xsum = tmp - sum;
                auto xcount = tot - count;
                if (s.count(encode(xcount, xsum)))
                    return true;
            }
        }
        return false;
    }
};

