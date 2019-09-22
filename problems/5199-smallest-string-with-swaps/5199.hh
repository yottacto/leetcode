#include <string>
#include <vector>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

struct Solution
{
    std::vector<int> parent;
    int n;

    int get_parent(int u)
    {
        return u == parent[u]
            ? u
            : parent[u] = get_parent(parent[u]);
    }

    void set_union(int u, int v)
    {
        auto tu = get_parent(u);
        auto tv = get_parent(v);
        if (tu != tv)
            parent[tu] = tv;
    }

    std::string smallestStringWithSwaps(std::string s, std::vector<std::vector<int>>& pairs)
    {
        n = s.size();
        parent.resize(n);
        std::iota(parent.begin(), parent.end(), 0);
        for (auto const& e : pairs)
            set_union(e[0], e[1]);
        std::unordered_map<int, std::priority_queue<char, std::vector<char>, std::greater<char>>> all;
        for (auto i = 0; i < n; i++)
            all[get_parent(i)].emplace(s[i]);
        std::string res;
        for (auto i = 0; i < n; i++) {
            res += all[get_parent(i)].top();
            all[get_parent(i)].pop();
        }
        return res;
    }
};

