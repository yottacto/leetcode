#pragma once
#include <set>
#include <utility>
#include <iterator>

#include <iostream>

auto constexpr inf = 1<<30;

struct RangeModule
{
    std::set<std::pair<int, int>> ranges;

    RangeModule()
    {
        ranges.emplace(-inf, -inf);
        ranges.emplace(+inf, +inf);
    }

    void print() const
    {
        #if DEBUG
        std::cout << "current ranges:\n";
        for (auto const& p : ranges) {
            if (p.first == -inf || p.first == +inf)
                continue;
            std::cout << p.first << " " << p.second << "\n";
        }
        #endif
    }

    void addRange(int left, int right)
    {
        auto it = std::prev(ranges.lower_bound(std::make_pair(left, right)));
        if (it->second >= left) {
            left = it->first;
            right = std::max(right, it->second);
            ranges.erase(it);
        }
        do {
            it = ranges.lower_bound(std::make_pair(left, right));
            if (right < it->first)
                break;
            right = std::max(right, it->second);
            ranges.erase(it);
        } while (true);
        ranges.emplace(left, right);
        print();
    }

    bool queryRange(int left, int right)
    {
        auto it = std::prev(ranges.lower_bound(std::make_pair(left, right)));
        if (it->second > left)
            left = it->second;
        if (left >= right)
            return true;
        it = ranges.lower_bound(std::make_pair(left, right));
        return it->first == left && it->second >= right;
    }

    void add_range(int l, int r)
    {
        if (l >= r) return;
        ranges.emplace(l, r);
    }

    void removeRange(int left, int right)
    {
        auto p = std::make_pair(left, right);
        auto it = std::prev(ranges.lower_bound(p));
        if (it->second > left) {
            add_range(it->first, left);
            add_range(right, it->second);
            ranges.erase(it);
        }
        do {
            it = ranges.lower_bound(p);
            if (right <= it->first)
                break;
            add_range(right, it->second);
            ranges.erase(it);
        } while (true);
        print();
   }
};

