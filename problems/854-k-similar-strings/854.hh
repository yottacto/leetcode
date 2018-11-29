#pragma once
#include <iostream>
#include <string>

#define DEBUG 1

struct Solution
{
    int graph[7][7];
    int path[7];
    int circle[7];
    int min_circle_length;
    bool vis[7];
    bool visited[7];
    int count_edge;

public:
    auto id(char ch) -> int
    {
        return ch - 'a';
    }

    void add_edge(int u, int v)
    {
        if (u != v) {
            graph[u][v]++;
            count_edge++;
        }
    }

    void remove_edge(int u, int v)
    {
        graph[u][v]--;
    }

    void init(int n)
    {
        min_circle_length = n;
        for (auto i = 0; i < 6; i++)
            vis[i] = visited[i] = false;
    }

    void remove_min_circle()
    {
        #if DEBUG
        std::cerr << "removing min circle: ";
        #endif

        circle[min_circle_length] = circle[0];
        for (auto i = 0; i < min_circle_length; i++) {
            #if DEBUG
            std::cerr << char('a' + circle[i]) << "->";
            #endif
            remove_edge(circle[i], circle[i + 1]);
        }
        #if DEBUG
        std::cerr << "\n";
        #endif
    }

    auto find_index(int u, int len)
    {
        for (auto i = 0; i < len; i++)
            if (path[i] == u)
                return i;
        // impossible
        return -1;
    }

    void dfs(int u, int step)
    {
        #if DEBUG
        std::cerr << "u=" << u << " step=" << step << "\n";
        #endif
        path[step] = u;
        vis[u] = visited[u] = true;
        for (auto v = 0; v < 6; v++) {
            if (graph[u][v] && vis[v]) {
                auto index_v = find_index(v, step);
                auto circle_len = step - index_v + 1;
                #if DEBUG
                std::cerr << "find circle on v=" << v << " len=" << circle_len << " " << "u=" << u << " g[u][v]=" << graph[u][v] << "\n";
                #endif
                if (circle_len < min_circle_length) {
                    min_circle_length = circle_len;
                    for (auto i = index_v; i <= step; i++)
                        circle[i - index_v] = path[i];
                }
            }
            if (graph[u][v] && !vis[v])
                dfs(v, step + 1);
        }
        vis[u] = false;
    }

    int kSimilarity(std::string a, std::string b)
    {
        int n = a.size();
        count_edge = 0;
        for (auto i = 0; i < 6; i++)
            for (auto j = 0; j < 6; j++)
                graph[i][j] = 0;

        for (auto i = 0; i < n; i++) {
            add_edge(id(a[i]), id(b[i]));
        }

        auto ans = 0;
        while (count_edge) {
            init(n);
            for (auto i = 0; i < 6; i++) {
                if (!visited[i])
                    dfs(i, 0);
            }
            count_edge -= min_circle_length;
            ans += min_circle_length - 1;
            remove_min_circle();
            // std::cerr << count_edge << "\n";
        }
        return ans;
    }
};

