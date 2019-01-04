#pragma once
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

struct Solution
{
    std::vector<int> movesToStamp(std::string stamp, std::string target)
    {
        int l = stamp.size();
        int n = target.size();
        std::vector<std::unordered_set<int>> made(n - l + 1);
        std::vector<std::unordered_set<int>> todo(n - l + 1);
        std::vector<char> vis(n + 1);
        for (auto i = 0; i <= n - l; i++) {
            for (auto j = 0; j < l; j++)
                if (stamp[j] == target[i + j]) {
                    made[i].emplace(i + j);
                } else {
                    todo[i].emplace(i + j);
                }
        }
        std::queue<int> q;
        std::vector<int> ans;
        auto count = 0;
        for (auto i = 0; i <= n - l; i++) {
            if (!todo[i].empty()) continue;
            ans.emplace_back(i);
            for (auto p : made[i]) {
                if (vis[p]) continue;
                vis[p] = true;
                count++;
                q.emplace(p);
            }
        }
        while (!q.empty() && count < n) {
            auto p = q.front();
            q.pop();
            // std::cerr << l << " " << n << " " << p << "\n";
            for (auto i = std::max(0, p - l + 1); i <= std::min(n - l, p); i++) {
                if (!todo[i].count(p))
                    continue;
                todo[i].erase(p);
                if (!todo[i].empty())
                    continue;
                ans.emplace_back(i);
                for (auto j : made[i]) {
                    if (vis[j]) continue;
                    vis[j] = true;
                    count++;
                    q.emplace(j);
                }
            }
        }
        if (count != n)
            return {};
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};

