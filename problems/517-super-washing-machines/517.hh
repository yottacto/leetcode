#pragma once
#include <algorithm>
#include <vector>
#include <numeric>

struct Solution
{
    int n;

    int findMinMoves(std::vector<int>& machines)
    {
        n = machines.size();
        auto sum = std::accumulate(machines.begin(), machines.end(), 0);
        if (sum % n)
            return -1;
        auto avg = sum / n;
        auto max = 0;
        sum = 0;
        for (auto i : machines) {
            max = std::max(std::max(max, i - avg), abs(i - avg + sum));
            sum = i - avg + sum;
        }
        return max;
    }
};

