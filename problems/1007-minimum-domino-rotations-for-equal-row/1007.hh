#pragma once
#include <vector>

auto constexpr inf = 1 << 30;

struct Solution
{
    int check(std::vector<int>& a, std::vector<int>& b, int x)
    {
        int n = a.size();
        auto count = 0;
        for (auto i = 0; i < n; i++) {
            if (a[i] == x)
                continue;
            if (b[i] == x) {
                count++;
                continue;
            }
            return inf;
        }
        return count;
    }

    int minDominoRotations(std::vector<int>& a, std::vector<int>& b)
    {
        auto res = std::min(
            std::min(check(a, b, a[0]), check(a, b, b[0])),
            std::min(check(b, a, a[0]), check(b, a, b[0]))
        );
        return res == inf
            ? -1
            : res;
    }
};

