#pragma once
#include <algorithm>
#include <unordered_set>
#include <functional>

struct Solution
{
    std::unordered_set<int> all;
    std::vector<std::function<bool(int)>> opt{
        [](int)   { return true;       },
        [](int i) { return !(i&1);     },
        [](int i) { return i&1;        },
        [](int i) { return i % 3 == 1; },
    };

    template <class Pred>
    int apply(int bulbs, int n, Pred pred)
    {
        for (auto i = 0; i < n; i++)
            if (pred(i+1))
                bulbs ^= 1<<i;
        return bulbs;
    }

    void dfs(int n, int depth, int num)
    {
        if (depth == 0) {
            all.insert(num);
            return;
        }
        for (auto i = 0; i < 4; i++)
            dfs(n, depth - 1, apply(num, n, opt[i]));
    }

    int flipLights(int n, int m)
    {
        // actually n = min(n, 3), first 3 lights can uniquely determine the
        // rest of lights
        n = std::min(n, 4);
        // actally m = min(m, 3), from m = 3 you can get all states
        m = std::min(m, 8);
        dfs(n, m, 0);
        return all.size();
    }
};

