#pragma once
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <iterator>

struct Solution
{
    int bestRotation(std::vector<int>& a)
    {
        int n = a.size();
        std::multiset<int> le;
        std::unordered_multiset<int> gt;
        for (auto i = 0; i < n; i++) {
            a[i] -= i;
            if (a[i] <= 0)
                le.insert(a[i]);
            else
                gt.insert(a[i]);
        }
        auto max = le.size();
        auto res = 0;
        for (auto d = 1; d < n; d++) {
            while (!le.empty() && *le.rbegin() + d > 0) {
                auto t = *le.rbegin();
                le.erase(std::prev(le.end()));
                gt.insert(t);
            }
            auto head = a[d - 1];
            if (head + d <= 0) {
                le.erase(le.find(head));
                le.insert(head - n);
            } else {
                gt.erase(gt.find(head));
                if (head + d - n <= 0)
                    le.insert(head - n);
                else
                    gt.insert(head - n);
            }
            if (le.size() > max) {
                max = le.size();
                res = d;
            }
        }
        return res;
    }
};

