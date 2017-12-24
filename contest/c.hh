#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>

class Solution
{
    std::unordered_map<std::string, int> vis;
    std::unordered_set<std::string> all;

    std::string next_move(std::string s, int p, int d)
    {
        auto num = s[p] - '0';
        num = ((num + d) + 10) % 10;
        s[p] = '0' + num;
        return s;
    }

public:
    int openLock(std::vector<std::string>& deadends, std::string target)
    {
        for (auto s : deadends) {
            all.insert(s);
            vis[s] = 1 << 30;
        }
        std::queue<std::string> q;
        if (all.count("0000"))
            return -1;
        q.push("0000");
        vis["0000"] = 0;
        while (!q.empty()) {
            auto now = q.front(); q.pop();
            auto dis = vis[now];
            // std::cerr << now << "\n";
            if (now == target)
                return dis;
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 2; j++) {
                    auto next = next_move(now, i, j * 2 - 1);
                    if (vis.count(next) || all.count(next)) continue;
                    vis[next] = dis + 1;
                    q.push(next);
                }
            }
        }
        return -1;
    }
};

