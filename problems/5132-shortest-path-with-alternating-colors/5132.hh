#include <vector>
#include <queue>

struct node
{
    int u;
    int d;
    int c;
};

struct Solution
{
    int map[200][200] = {};
    bool vis[200][3] = {};

    // red 1, blue 2
    std::vector<int> shortestAlternatingPaths(int n, std::vector<std::vector<int>>& red_edges, std::vector<std::vector<int>>& blue_edges)
    {
        std::vector<int> ans(n, 1<<30);
        for (auto const& v : red_edges) {
            map[v[0]][v[1]] |= 1;
        }
        for (auto const& v : blue_edges) {
            map[v[0]][v[1]] |= 2;
        }
        for (auto i = 0; i < n; i++)
            ans[i] = 1<<30;
        ans[0] = 0;
        std::queue<node> q;
        for (auto i = 0; i < n; i++) {
            if (map[0][i] & 1) {
                vis[i][1] = true;
                q.emplace(node{i, 1, 1});
                ans[i] = std::min(ans[i], 1);
            }
            if (map[0][i] & 2) {
                vis[i][2] = true;
                q.emplace(node{i, 1, 2});
                ans[i] = std::min(ans[i], 1);
            }
        }
        while (!q.empty()) {
            auto [u, d, c] = q.front();
            q.pop();
            auto nc = 3 ^ c;
            for (auto i = 0; i < n; i++) {
                if ((map[u][i] & nc) && !vis[i][nc]) {
                    vis[i][nc] = true;
                    ans[i] = std::min(ans[i], d + 1);
                    q.emplace(node{i, d + 1, nc});
                }
            }
        }
        for (auto& i : ans)
            if (i == 1<<30)
                i = -1;
        return ans;
    }
};

