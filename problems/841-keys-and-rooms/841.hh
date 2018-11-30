#pragma once
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

struct Solution
{
    bool canVisitAllRooms(std::vector<std::vector<int>>& rooms)
    {
        int n = rooms.size();
        std::vector<char> vis(n);
        std::queue<int> q;
        q.push(0);
        while (!q.empty()) {
            auto now = q.front();
            q.pop();
            vis[now] = 1;
            for (auto k : rooms[now]) {
                if (vis[k]) continue;
                q.push(k);
            }
        }
        return std::adjacent_find(vis.begin(), vis.end(), std::not_equal_to<int>{})
            == vis.end();
    }
};

