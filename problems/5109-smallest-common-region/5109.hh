#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

struct Solution
{
    std::unordered_map<std::string, int> id;
    std::vector<std::string> names;
    std::unordered_map<int, int> parent;
    int tot{};

    int get_id(std::string const& name)
    {
        if (id.count(name))
            return id.at(name);
        names.emplace_back(name);
        return id[name] = tot++;
    }

    void add_edge(int u, int v)
    {
        parent[v] = u;
    }

    int lca(int u, int v)
    {
        std::unordered_set<int> parents;
        parents.emplace(u);
        while (parent.count(u)) {
            u = parent[u];
            parents.emplace(u);
        }
        do {
            if (parents.count(v))
                return v;
            v = parent[v];
        } while (true);
        return -1;
    }

    std::string findSmallestRegion(std::vector<std::vector<std::string>>& regions, std::string region1, std::string region2)
    {
        for (auto const& l : regions) {
            auto u = get_id(l[0]);
            for (auto i = 1u; i < l.size(); i++) {
                auto v = get_id(l[i]);
                add_edge(u, v);
            }
        }
        auto u = get_id(region1);
        auto v = get_id(region2);
        return names[lca(u, v)];
    }
};

