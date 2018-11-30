#pragma once
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

#include <iostream>

auto constexpr inf = 1<<30;

struct Solution
{
    std::unordered_map<std::string, int> id;
    int s;
    int t;
    int n;
    int len;
    std::string begin;
    std::string end;
    std::vector<std::unordered_set<int>> g;
    std::vector<std::string> words;
    std::vector<int> dis;
    std::vector<std::vector<std::string>> res;

    void add_edge(int u, int v)
    {
        // std::cerr << u << " -> " << v << "\n";
        g[u].insert(v);
        g[v].insert(u);
    }

    void connect(std::string const& s)
    {
        auto u = id.at(s);
        for (auto i = 0; i < len; i++) {
            auto tmp = s;
            for (auto ch = 'a'; ch <= 'z'; ch++) {
                if (ch == s[i]) continue;
                tmp[i] = ch;
                if (id.count(tmp))
                    add_edge(u, id.at(tmp));
            }
        }
    }

    void build_graph()
    {
        g.resize(n);
        for (auto const& s : words)
            connect(s);
    }

    void bfs(int s)
    {
        std::queue<int> q;
        q.push(s);
        dis.resize(n, inf);
        dis[s] = 0;
        while (!q.empty()) {
            auto u = q.front();
            if (u == t) break;
            q.pop();
            for (auto v : g[u]) {
                if (dis[v] != inf)
                    continue;
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }

    template <class V>
    void dfs(int u, V& path)
    {
        // std::cerr << "in " << u << "\n";
        path.emplace_back(words[u]);
        if (u == s) {
            res.emplace_back(path.rbegin(), path.rend());
            path.pop_back();
            return;
        }
        auto len = dis[u];
        for (auto v : g[u]) {
            if (dis[v] != len - 1)
                continue;
            dfs(v, path);
        }
        path.pop_back();
        // std::cerr << "out " << u << "\n";
    }

    std::vector<std::vector<std::string>> findLadders(
        std::string beginWord,
        std::string endWord,
        std::vector<std::string> const& wordList
    )
    {
        begin = beginWord;
        end = endWord;
        words = wordList;
        n = words.size();
        len = begin.size();
        for (auto i = 0; i < n; i++)
            id[wordList[i]] = i;
        if (id.count(begin)) {
            s = id.at(begin);
        } else {
            id[begin] = s = n++;
            words.emplace_back(begin);
        }
        if (!id.count(end)) return {};
        t = id.at(end);

        build_graph();

        // std::cerr << "graph:\n";
        // for (auto i = 0; i < n; i++) {
        //     std::cerr << i << ": ";
        //     for (auto v : g[i])
        //         std::cerr << v << ", ";
        //     std::cerr << "\n";
        // }

        bfs(s);

        // std::cerr << "s=" << s << ", t=" << t << "\n";
        // for (auto i = 0; i < n; i++)
        //     std::cerr << "dis[" << i << "]=" << dis[i] << "\n";

        std::vector<std::string> path;
        dfs(t, path);
        return res;
    }
};

