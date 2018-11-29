#pragma once
#include <algorithm>
#include <vector>

struct Solution
{
    int numRescueBoats(std::vector<int>& people, int limit)
    {
        std::sort(people.begin(), people.end());
        int n = people.size();
        auto l = 0;
        auto r = n - 1;
        auto count = 0;
        for (; l < r; r--, count++)
            if (people[l] + people[r] <= limit)
                l++;
        return count + (l == r);
    }
};

