#pragma once
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

struct Solution
{
    std::vector<std::vector<int>> g;
    std::vector<int> indegree;
    std::vector<int> dis;
    std::vector<int> right;
    int n;

    bool pred(std::string const& a, std::string const& b)
    {
        if (a.size() + 1 != b.size())
            return false;
        auto c = b[0] + a;
        auto left = true;
        int n = b.size();
        right[n] = true;
        right[n - 1] = b[n - 1] == c[n - 1];
        for (auto i = n - 2; i >= 0; i--)
            right[i] = right[i + 1] && (b[i] == c[i]);
        for (auto i = 0; i < b.size(); i++) {
            if (left && right[i + 1])
                return true;
            if (i != b.size() - 1) {
                std::swap(c[i], c[i + 1]);
                left &= c[i] == b[i];
                if (!left)
                    return false;
                c[i + 1] = b[i + 1];
            }
        }
        return false;
    }

    void add_edge(int u, int v)
    {
        g[u].emplace_back(v);
        indegree[v]++;
    }

    int longestStrChain(std::vector<std::string>& words)
    {
        n = words.size();
        g.resize(n);
        indegree.resize(n);
        dis.resize(n, 1);
        right.resize(30);
        for (auto i = 0; i < n; i++)
            for (auto j = 0; j < n; j++) {
                if (i == j) continue;
                if (pred(words[i], words[j])) {
                    add_edge(i, j);
                }
            }
        std::queue<int> q;
        for (auto i = 0; i < n; i++)
            if (!indegree[i])
                q.emplace(i);
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            for (auto v : g[u]) {
                dis[v] = std::max(dis[v], dis[u] + 1);
                indegree[v]--;
                if (!indegree[v])
                    q.emplace(v);
            }
        }
        auto max = 0;
        for (auto i = 0; i < n; i++)
            max = std::max(max, dis[i]);
        return max;
    }
};

