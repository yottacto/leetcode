#pragma once
#include <algorithm>
#include <vector>

// // Definition for an interval.
// struct Interval
// {
//     int start;
//     int end;
//     Interval() : start(0), end(0) {}
//     Interval(int s, int e) : start(s), end(e) {}
// };

struct Solution
{
    std::vector<Interval> insert(std::vector<Interval>& intervals, Interval newInterval)
    {
        auto range = std::equal_range(intervals.begin(), intervals.end(), newInterval, [](auto const& a, auto const& b) {
            return a.end < b.start;
        });
        auto it1 = range.first;
        auto it2 = range.second;
        if (it1 == it2) {
            intervals.insert(it1, newInterval);
        } else {
            it2--;
            it2->start = std::min(newInterval.start, it1->start);
            it2->end = std::max(newInterval.end, it2->end);
            intervals.erase(it1, it2);
        }
        return intervals;
    }
};

