#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

struct Solution
{
    std::vector<std::vector<int>> gg;
    std::vector<int> in_g;
    std::vector<int> res;
    std::vector<std::vector<int>> all;

    std::vector<std::vector<int>> g;
    std::vector<int> in;
    std::vector<std::vector<int>> before;
    std::vector<int> group;


    void add_edge(int u, int v)
    {
        gg[u].emplace_back(v);
        in_g[v]++;
    }

    bool insert(int now)
    {
        auto const& a = all[now];
        for (auto i : a)
            for (auto j : before[i]) {
                if (group[j] != now)
                    continue;
                g[j].emplace_back(i);
                in[i]++;
            }

        std::queue<int> q;
        for (auto i : a)
            if (!in[i])
                q.emplace(i);

        auto count = 0;
        while (!q.empty()) {
            auto cur = q.front();
            res.emplace_back(cur);
            q.pop();
            count++;
            for (auto v : g[cur]) {
                in[v]--;
                if (!in[v])
                    q.emplace(v);
            }
        }

        if (count < (int)a.size())
            return false;
        return true;
    }

    std::vector<int> sortItems(int n, int m, std::vector<int>& group, std::vector<std::vector<int>>& before)
    {
        for (auto& i : group)
            if (i == -1)
                i = m++;
        this->before = before;
        this->group = group;
        all.resize(m);
        for (auto i = 0; i < n; i++)
            all[group[i]].emplace_back(i);
        gg.resize(m);
        in_g.resize(m);
        g.resize(n);
        in.resize(n);
        for (auto i = 0; i < n; i++)
            for (auto j : before[i])
                if (group[j] != group[i])
                    add_edge(group[j], group[i]);
        std::queue<int> q;
        for (auto i = 0; i < m; i++)
            if (!in_g[i])
                q.emplace(i);
        auto count = 0;
        while (!q.empty()) {
            auto now = q.front();
            // std::cerr << "~" << now << "\n";
            q.pop();
            count++;
            if (!insert(now)) {
                // std::cerr << "fuck " << now << "\n";
                return {};
            }
            for (auto v : gg[now]) {
                in_g[v]--;
                if (!in_g[v])
                    q.emplace(v);
            }
        }
        if (count < m)
            return {};
        return res;
    }
};

