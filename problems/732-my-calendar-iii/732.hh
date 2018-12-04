#pragma once
#include <map>

struct MyCalendarThree
{
    std::map<int, int> count;

    int book(int start, int end)
    {
        count[start]++;
        count[end]--;
        auto res = 0;
        auto sum = 0;
        for (auto it : count) {
            sum += it.second;
            res = std::max(res, sum);
        }
        return res;
    }
};

