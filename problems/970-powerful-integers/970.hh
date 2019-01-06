#pragma once
#include <vector>
#include <set>

struct Solution
{
    std::vector<int> powerfulIntegers(int x, int y, int bound)
    {
        std::set<int> all;
        auto tx = 1;
        for (auto i = 0; i <= 20; i++) {
            auto ty = 1;
            for (auto j = 0; j <= 20; j++) {
                if (tx + ty > bound)
                    break;
                all.insert(tx + ty);
                ty *= y;
                if (ty > bound) break;
            }
            tx *= x;
            if (tx > bound) break;
        }
        return {all.begin(), all.end()};
    }
};

