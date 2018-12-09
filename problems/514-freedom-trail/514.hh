#pragma once
#include <string>
#include <utility>

auto constexpr inf = 1<<30;
auto constexpr maxn = 207;

struct Solution
{
    int f[maxn][maxn];
    int n;
    int m;
    std::string ring;

    auto next(int p, char ch, int dir) -> std::pair<int, int>
    {
        auto delta = 0;
        for (; ring[p-1] != ch; delta++) {
            p += dir;
            if (p > m) p = 1;
            else if (p == 0) p = m;
        }
        return {p, delta};
    }

    int findRotateSteps(std::string const& ring, std::string const& key)
    {
        this->ring = ring;
        m = ring.size();
        n = key.size();
        for (auto i = 0; i <= n; i++)
            for (auto j = 0; j <= m; j++)
                f[i][j] = inf;
        f[0][1] = 0;
        for (auto i = 0; i < n; i++) {
            for (auto j = 1; j <= m; j++) {
                if (f[i][j] == inf) continue;
                {
                    auto p = next(j, key[i], 1);
                    auto tj = p.first;
                    auto delta = p.second;
                    f[i+1][tj] = std::min(f[i+1][tj], f[i][j] + delta + 1);
                }
                {
                    auto p = next(j, key[i], -1);
                    auto tj = p.first;
                    auto delta = p.second;
                    f[i+1][tj] = std::min(f[i+1][tj], f[i][j] + delta + 1);
                }
            }
        }
        auto res = inf;
        for (auto i = 1; i <= m; i++)
            res = std::min(res, f[n][i]);
        return res;
    }
};

