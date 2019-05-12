#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>

std::vector<std::vector<int>> dir{
    {-1, 0}, {0, 1}, {1, 0}, {0, -1},
};

struct Solution
{
    bool isRobotBounded(std::string instructions)
    {
        auto d = 0;
        auto cur = std::make_pair(0, 0);
        for (auto i = 0; i <= 100; i++) {
            for (auto ch : instructions) {
                if (ch == 'L') {
                    d--;
                    if (d == -1)
                        d = 3;
                } else if (ch == 'R') {
                    d++;
                    if (d == 4)
                        d = 0;
                } else {
                    auto next = cur;
                    next.first += dir[d][0];
                    next.second += dir[d][1];
                    cur = next;
                }
            }
            if (cur == std::make_pair(0, 0) && d == 0)
                return true;
        }
        return false;
    }
};

