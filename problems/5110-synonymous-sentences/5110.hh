#include <algorithm>
#include <vector>
#include <string>
#include <set>

struct Solution
{
    std::unordered_map<std::string, int> id;
    std::unordered_map<int, int> parent;
    std::unordered_map<int, std::set<std::string>> all;
    int tot{};

    std::vector<std::string> res;

    int get_id(std::string const& n)
    {
        if (id.count(n))
            return id.at(n);
        parent[tot] = tot;
        return id[n] = tot++;
    }

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

    void dfs(int l, int n, std::string const& text, std::string const& prev, std::string const& now)
    {
        if (l == n) {
            auto i = get_parent(get_id(now));
            all[i].emplace(now);
            for (auto const& s : all[i]) {
                res.emplace_back(prev + s);
            }
        } else if (text[l] == ' ') {
            auto i = get_parent(get_id(now));
            all[i].emplace(now);
            for (auto const& s : all[i])
                dfs(l + 1, n, text, prev + s + ' ', "");
        } else {
            dfs(l + 1, n, text, prev, now + text[l]);
        }
    }

    std::vector<std::string> generateSentences(std::vector<std::vector<std::string>>& synonyms, std::string text)
    {
        for (auto const& p : synonyms) {
            auto u = get_id(p[0]);
            auto v = get_id(p[1]);
            set_union(u, v);
        }
        for (auto const& p : id) {
            // std::cout << p.first << " " << p.second << "\n";
            all[get_parent(p.second)].emplace(p.first);
        }

        // std::cout << " =================\n";
        // for (auto& p : all) {
        //     std::cout << p.first << " ";
        //     for (auto s : p.second)
        //         std::cout << s << " ";
        //     std::cout << "\n";
        // }

        dfs(0, text.size(), text, "", "");
        return res;
    }
};

