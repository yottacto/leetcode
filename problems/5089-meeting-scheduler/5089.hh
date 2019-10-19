#include <vector>
#include <algorithm>
#include <map>
#include <iterator>

struct Solution
{
    template <class T>
    bool check(T const& a, int start, int d)
    {
        auto it = a.upper_bound(start);
        if (it == a.begin())
            return false;
        it = std::prev(it);
        return it->second >= start + d;
    }

    std::vector<int> minAvailableDuration(std::vector<std::vector<int>>& slots1, std::vector<std::vector<int>>& slots2, int duration)
    {
        std::map<int, int> a1;
        std::map<int, int> a2;
        std::vector<int> all;
        for (auto const& v : slots1) {
            a1[v[0]] = v[1];
            all.emplace_back(v[0]);
        }
        for (auto const& v : slots2) {
            a2[v[0]] = v[1];
            all.emplace_back(v[0]);
        }
        std::sort(all.begin(), all.end());
        for (auto start : all) {
            if (check(a1, start, duration) && check(a2, start, duration))
                return {start, start + duration};
        }
        return {};
    }
};

