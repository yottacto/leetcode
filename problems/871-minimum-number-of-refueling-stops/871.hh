#pragma once
#include <vector>
#include <queue>

struct Solution
{
    int minRefuelStops(int target, int startFuel, std::vector<std::vector<int>>& stations)
    {
        stations.emplace_back(std::vector{target, 0});
        auto tot = 0;
        std::priority_queue<int> backup;
        for (auto const& s : stations) {
            if (startFuel < s[0]) {
                while (!backup.empty() && startFuel < s[0]) {
                    tot++;
                    startFuel += backup.top();
                    backup.pop();
                }
                if (startFuel < s[0])
                    return -1;
            }
            backup.emplace(s[1]);
        }
        return tot;
    }
};

