#pragma once
#include <vector>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <iterator>

auto constexpr maxn = 100;

struct Solution
{
    int n;
    int m;
    int wall{};
    bool vis[maxn][maxn] = {};
    std::set<int> blocks;
    std::map<int, std::set<int>> virus;
    std::vector<std::vector<int>> dir{{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};
    std::vector<std::vector<int>> grid;
    std::map<int, std::set<int>> adj;

    int id(int x, int y) { return x * m + y; }
    auto inrange(int x, int l, int r) { return l <= x && x < r; }
    auto inrange(int x, int y) { return inrange(x, 0, n) && inrange(y, 0, m); }

    void bfs(int x, int y, std::set<int>& s)
    {
        std::queue<std::pair<int, int>> q;
        q.push({x, y});
        while (!q.empty()) {
            auto now = q.front();
            auto x = now.first;
            auto y = now.second;
            s.insert(id(x, y));
            q.pop();
            for (auto const& d : dir) {
                auto nx = x + d[0];
                auto ny = y + d[1];
                if (!inrange(nx, ny) || !grid[nx][ny] || vis[nx][ny]) continue;
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    void generate_adj_and_remove_max_block()
    {
        auto max = -1;
        auto max_bid = 0;
        auto max_wall_needed = 0;
        adj.clear();
        for (auto bid : blocks) {
            auto wall_needed = 0;
            for (auto vid : virus[bid]) {
                auto x = vid / m;
                auto y = vid % m;
                for (auto const& d: dir) {
                    auto nx = x + d[0];
                    auto ny = y + d[1];
                    auto nid = id(nx, ny);
                    if (!inrange(nx, ny) || grid[nx][ny])
                        continue;
                    wall_needed++;
                    adj[bid].insert(nid);
                }
            }
            if ((int)adj[bid].size() > max) {
                max = adj[bid].size();
                max_bid = bid;
                max_wall_needed = wall_needed;
            }
        }
        wall += max_wall_needed;
        blocks.erase(max_bid);
        virus.erase(max_bid);
        adj.erase(max_bid);
    }

    auto has_common(int bid1, int bid2)
    {
        for (auto v : adj[bid1]) {
            if (adj[bid2].count(v))
                return true;
            auto x = v/m;
            auto y = v%m;
            for (auto const& d : dir) {
                auto nx = x + d[0];
                auto ny = y + d[1];
                if (inrange(nx, ny) && adj[bid2].count(id(nx, ny)))
                    return true;
            }
        }
        return false;
    }

    void merge()
    {
        auto merged = false;
        do {
            merged = false;
            for (auto it = blocks.begin(); it != blocks.end(); ++it) {
                for (auto it2 = std::next(it); it2 != blocks.end(); ) {
                    if (has_common(*it, *it2)) {
                        adj[*it].insert(adj[*it2].begin(), adj[*it2].end());
                        virus[*it].insert(virus[*it2].begin(), virus[*it2].end());
                        adj.erase(*it2);
                        virus.erase(*it2);
                        it2 = blocks.erase(it2);
                        merged = true;
                    } else {
                        ++it2;
                    }
                }
            }
        } while (merged);
        for (auto bid : blocks) {
            virus[bid].insert(adj[bid].begin(), adj[bid].end());
            for (auto vid : adj[bid])
                grid[vid/m][vid%m] = 1;
        }
    }

    auto total_virus()
    {
        auto sum = 0;
        for (auto i = 0; i < n; i++)
            for (auto j = 0; j < m; j++)
                sum += grid[i][j];
        return sum;
    }

    int containVirus(std::vector<std::vector<int>> const& grid)
    {
        this->grid = grid;
        n = grid.size();
        m = grid[0].size();
        for (auto i = 0; i < n; i++)
            for (auto j = 0; j < m; j++) {
                if (vis[i][j] || !grid[i][j]) continue;
                vis[i][j] = true;
                auto block_id = id(i, j);
                blocks.insert(block_id);
                bfs(i, j, virus[block_id]);
            }
        while (!blocks.empty() && total_virus() < n * m) {
            generate_adj_and_remove_max_block();
            merge();
        }
        return wall;
    }
};

