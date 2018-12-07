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

auto operator<(Interval const& lhs, Interval const& rhs)
{
    return lhs.start < rhs.start;
}

auto constexpr inf = 1<<30;

struct SummaryRanges
{
    std::vector<Interval> intervals;

    /** Initialize your data structure here. */
    SummaryRanges()
    {
        intervals.emplace_back(-inf, -inf);
    }

    auto inrange(int x, int l, int r)
    {
        return l <= x && x <= r;
    }

    bool merge(int p1, int p2)
    {
        auto& int1       = intervals[p1];
        auto const& int2 = intervals[p2];
        if (inrange(int2.start, int1.start, int1.end)
            || int2.start == int1.end + 1) {
            int1.end = std::max(int1.end, int2.end);
            return true;
        }
        return false;
    }

    void merge(int p)
    {
        auto i = p + 1;
        for (; i < (int)intervals.size(); i++)
            if (!merge(p, i))
                break;
        intervals.erase(intervals.begin() + p + 1, intervals.begin() + i);
    }

    void addNum(int val)
    {
        auto v = Interval{val, val};
        auto p = std::upper_bound(intervals.begin(), intervals.end(), v) - intervals.begin();
        intervals.insert(intervals.begin() + p, v);
        merge(--p);
        merge(p + 1);
    }

    std::vector<Interval> getIntervals()
    {
        return {intervals.begin() + 1, intervals.end()};
    }
};

