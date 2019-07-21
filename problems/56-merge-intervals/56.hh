#include <algorithm>
#include <initializer_list>
#include <vector>
#include <map>

struct Solution
{
    std::map<int, int> um;

    void insert(std::vector<int> v)
    {
        auto it = um.lower_bound(v[0]);
        // processing prev interval
        if (it != um.begin() && std::prev(it)->second >= v[0]) {
            auto p = *std::prev(it);
            it = um.erase(std::prev(it));
            v[0] = p.first;
            v[1] = std::max(v[1], p.second);
        }
        for (; it != um.end() && v[1] >= it->first; ) {
            v[1] = std::max(v[1], it->second);
            it = um.erase(it);
        }
        um[v[0]] = v[1];
    }

    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals)
    {
        for (auto const& v : intervals)
            insert(v);
        std::vector<std::vector<int>> res;
        for (auto const& p : um)
            res.emplace_back(std::initializer_list<int>({p.first, p.second}));
        return res;
    }
};

