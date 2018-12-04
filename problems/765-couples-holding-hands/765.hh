#pragma once
#include <algorithm>
#include <vector>

struct Solution
{
    int minSwapsCouples(std::vector<int>& row)
    {
        auto seat = row;
        int n = row.size();
        for (auto i = 0; i < n; i++)
            seat[row[i]] = i;
        auto res = 0;
        for (auto i = 0; i < n; i += 2) {
            auto target = seat[i] ^ 1;
            if (seat[i+1] == target)
                continue;
            row[seat[i+1]] = row[target];
            std::swap(seat[i + 1], seat[row[target]]);
            row[target] = i + 1;
            res++;
        }
        return res;
    }
};

