#pragma once
#include <unordered_map>
#include <cmath>

struct Solution
{
    std::unordered_map<int, int> dis;

    int racecar(int target)
    {
        if (!target) return 0;
        if (dis.count(target))
            return dis[target];
        auto step = static_cast<int>(std::floor(std::log2(target))) + 1;
        if ((1<<step) - 1 == target)
            return dis[target] = step;
        dis[target] = racecar((1<<step) - 1 - target) + step + 1;
        for (auto i = 0; i < step-1; i++) {
            dis[target] = std::min(
                dis[target],
                racecar(target - ((1<<(step-1)) - (1<<i))) + step + i + 1
            );
        }
        return dis[target];
    }
};

