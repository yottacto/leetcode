#pragma once
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

auto constexpr maxl = 16;
auto constexpr inf = 1<<30;

struct Solution
{
    int l;
    int n;
    int f[1<<maxl];
    std::string target;

    auto add(int st, std::string const& s) -> int
    {
        auto it = s.begin();
        for (auto i = 0; i < l; i++) {
            if (st&(1<<i)) continue;
            while (it != s.end() && *it < target[i])
                ++it;
            if (it == s.end())
                break;
            if (*it == target[i]) {
                st ^= 1<<i;
                ++it;
            }
        }
        return st;
    }

    int minStickers(std::vector<std::string>& stickers, std::string target)
    {
        std::sort(target.begin(), target.end());
        this->target = target;
        n = stickers.size();
        l = target.size();

        // remove redundancy
        std::unordered_set<char> all_chars{target.begin(), target.end()};
        for (auto& s : stickers) {
            for (auto it = s.begin(); it != s.end(); )
                if (!all_chars.count(*it)) {
                    it = s.erase(it);
                } else {
                    ++it;
                }
            std::sort(s.begin(), s.end());
        }

        std::queue<int> q;
        std::unordered_map<int, int> dis;
        q.push(0);
        dis[0] = 0;
        while (!q.empty()) {
            auto now = q.front();
            q.pop();
            auto d = dis[now];
            for (auto i = 0; i < n; i++) {
                auto next = add(now, stickers[i]);
                if (dis.count(next)) continue;
                dis[next] = d + 1;
                q.push(next);
            }
        }

        if (!dis.count((1<<l)-1))
            return -1;
        else
            return dis[(1<<l) - 1];
    }
};

