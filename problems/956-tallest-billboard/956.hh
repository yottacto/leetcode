#pragma once
#include <algorithm>
#include <vector>
#include <unordered_map>

struct Solution
{
    void update(std::unordered_map<int, int>& f, int pos, int value)
    {
        if (f.count(pos))
            f[pos] = std::max(f[pos], value);
        else
            f[pos] = value;
    }

    int tallestBillboard(std::vector<int>& rods)
    {
        int n = rods.size();
        std::unordered_map<int, int> f[2];
        auto prev = 1;
        auto now = 0;
        f[now][0] = 0;
        for (auto i = 0; i < n; i++) {
            std::swap(prev, now);
            for (auto const& p : f[prev]) {
                auto sum = p.first;
                auto score = p.second;
                update(f[now], sum, score);
                update(f[now], sum + rods[i], score + rods[i]);
                update(f[now], sum - rods[i], score);
            }
        }
        return f[now][0];
    }
};

