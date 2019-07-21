#include <vector>
#include <queue>

struct Solution
{
    int n;
    std::vector<int> in;
    std::vector<std::vector<int>> g;

    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites)
    {
        n = numCourses;
        in.resize(n);
        g.resize(n);
        for (auto const& v : prerequisites) {
            g[v[1]].emplace_back(v[0]);
            in[v[0]]++;
        }
        std::queue<int> q;
        for (auto i = 0; i < n; i++)
            if (!in[i])
                q.emplace(i);
        int count = q.size();
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            for (auto const& v : g[u]) {
                in[v]--;
                if (!in[v]) {
                    q.emplace(v);
                    count++;
                }
            }
        }
        return count == n;
    }
};

