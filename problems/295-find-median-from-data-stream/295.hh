#pragma once
#include <set>

struct MedianFinder
{
    std::multiset<int> ms;

    using iterator = decltype(ms)::iterator;
    iterator l;
    iterator r;

    void addNum(int num)
    {
        auto n = ms.size();
        ms.emplace(num);
        if (!n) {
            l = r = ms.begin();
            return;
        }
        if (n & 1) {
            if (num < *l)
                l--;
            else
                r++;
            return;
        }
        if (*l < num && num < *r) {
            l++;
            r--;
        } else if (num >= *r) {
            l++;
        } else {
            l = --r;
        }
    }

    double findMedian()
    {
        return (*l + *r) / 2.;
    }
};

