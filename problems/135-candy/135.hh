#pragma once
#include <algorithm>
#include <numeric>
#include <vector>
#include <deque>
#include <limits>

auto constexpr inf = std::numeric_limits<int>::max();

class Solution
{
    std::vector<int> count;
public:
    int candy(std::vector<int>& ratings)
    {
        int n = ratings.size();
        if (n == 1) return 1;
        count.resize(n);

        count[0] = 1;
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1])
                count[i] = count[i - 1] + 1;
            else
                count[i] = 1;
        }

        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1])
                count[i] = std::max(count[i], count[i + 1] + 1);
        }

        return std::accumulate(count.begin(), count.end(), 0);
    }
};

