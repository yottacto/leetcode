#include <vector>
#include <unordered_set>
#include <algorithm>

struct Solution
{
    std::unordered_set<int> vis;
    std::vector<int> res;
    int n;

    void dfs(int u)
    {
        vis.emplace(u);
        for (auto i = 0; i < n; i++) {
            auto v = u ^ (1<<i);
            if (vis.count(v))
                continue;
            dfs(v);
        }
        res.emplace_back(u);
    }

    std::vector<int> circularPermutation(int n, int start)
    {
        this->n = n;
        dfs(start);
        std::reverse(res.begin(), res.end());
        return res;
    }
};

