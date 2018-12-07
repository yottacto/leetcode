#pragma once
#include <algorithm>
#include <vector>
#include <tuple>
#include <set>
#include <utility>

#include <iostream>

using ll = long long;

auto constexpr mo = 1000000007ll;

struct Solution
{
    using rect_type = std::vector<int>;
    using event = std::tuple<int, int, int, int>;

    std::vector<event> events;
    std::multiset<std::pair<int, int>> intervals;

    auto x1(rect_type const& r) const { return r[0]; }
    auto y1(rect_type const& r) const { return r[1]; }
    auto x2(rect_type const& r) const { return r[2]; }
    auto y2(rect_type const& r) const { return r[3]; }

    ll length()
    {
        if (intervals.empty()) return 0;
        auto sum = 0ll;
        auto last = *intervals.begin();
        for (auto it = intervals.begin(); it != intervals.end(); ) {
            while (it != intervals.end() && it->first <= last.second) {
                last.second = std::max(last.second, it->second);
                ++it;
            }
            sum = (sum + last.second - last.first) % mo;
            last = *it;
        }
        return sum;
    }

    int rectangleArea(std::vector<rect_type> const& rect)
    {
        events.reserve(2 * rect.size());
        for (auto const& r : rect) {
            events.emplace_back(x1(r), 1, y1(r), y2(r));
            events.emplace_back(x2(r), 0, y1(r), y2(r));
        }
        std::sort(events.begin(), events.end());

        auto last = std::get<0>(events[0]);
        auto sum = 0ll;
        for (auto const& e : events) {
            sum += (length() * (std::get<0>(e) - last)) % mo;
            sum %= mo;
            if (std::get<1>(e)) {
                intervals.insert({std::get<2>(e), std::get<3>(e)});
            } else {
                intervals.erase(intervals.find({std::get<2>(e), std::get<3>(e)}));
            }
            last = std::get<0>(e);
        }
        return sum;
    }
};

