#pragma once
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

std::string const target = "123450";
std::vector<std::vector<int>> dir{
    {1, 3},
    {0, 2, 4},
    {1, 5},
    {0, 4},
    {3, 5, 1},
    {4, 2},
};

struct Solution
{
    std::string start;
    std::unordered_map<std::string, int> dis;

    auto get_zero(std::string const& s)
    {
        for (int i = 0; i < 6; i++)
            if (s[i] == '0')
                return i;
        return -1;
    }

    int slidingPuzzle(std::vector<std::vector<int>>& board)
    {
        for (auto i = 0; i < 2; i++)
            for (auto j = 0; j < 3; j++)
                start += std::to_string(board[i][j]);
        dis[start] = 0;
        std::queue<std::string> q;
        q.push(start);
        while (!q.empty()) {
            auto now = q.front();
            if (now == target) return dis[now];
            q.pop();
            auto p = get_zero(now);
            for (auto m : dir[p]) {
                auto next = now;
                std::swap(next[p], next[m]);
                if (dis.count(next))
                    continue;
                dis[next] = dis[now] + 1;
                q.push(next);
            }
        }
        return -1;
    }
};

