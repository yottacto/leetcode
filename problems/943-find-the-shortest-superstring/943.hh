#pragma once
#include <algorithm>
#include <string>
#include <vector>

auto constexpr maxn = 13;
auto constexpr inf = (1u)<<30;

struct Solution
{
    int n;
    // TODO
    std::vector<std::vector<std::string>> f;
    std::string delta[maxn][maxn] = {};

    auto extend(std::string const& a, std::string const& b)
    {
        auto l = std::min<int>(a.size(), b.size());
        while (l--)
            if (a.substr(a.size() - l) == b.substr(0, l))
                return b.substr(l);
        return b.substr(0);
    }

    std::string shortestSuperstring(std::vector<std::string>& a)
    {
        n = a.size();
        f.resize(1<<n, std::vector<std::string>(n));

        for (auto i = 0; i < n; i++)
            for (auto j = 0; j < n; j++)
                if (i != j)
                    delta[i][j] = extend(a[i], a[j]);

        for (auto st = 1; st < (1<<n); st++) {
            for (auto to = 0; to < n; to++) {
                if (!(st & (1<<to))) continue;
                auto tst = st ^ (1<<to);
                if (!tst) {
                    f[st][to] = a[to];
                    continue;
                }
                auto len = inf;
                for (auto from = 0; from < n; from++) {
                    if (!(tst & (1<<from))) continue;
                    if (f[tst][from].size() + delta[from][to].size() < len) {
                        f[st][to] = f[tst][from] + delta[from][to];
                        len = f[st][to].size();
                    }
                }
            }
        }
        auto min = inf;
        std::string res;
        for (auto i = 0; i < n; i++)
            if (f[(1<<n) - 1][i].size() < min) {
                min = f[(1<<n) - 1][i].size();
                res = f[(1<<n) - 1][i];
            }

        return res;
    }
};

