#pragma once
#include <vector>
#include <algorithm>
#include <map>

struct Solution
{
    std::map<int, int> m;

    template <class Iter>
    auto check(Iter& it, int w) -> bool
    {
        while (!it->second)
            ++it;
        auto start = it->first;
        for (auto i = 0; i < w; i++) {
            if (m[start + i] == 0)
                return false;
            m[start + i]--;
        }
        return true;
    }

    bool isNStraightHand(std::vector<int>& hand, int w)
    {
        if (hand.size() % w)
            return false;
        for (auto i : hand)
            m[i]++;

        auto it = m.begin();
        auto block = hand.size() / w;
        for (auto i = 0u; i < block; i++)
            if (!check(it, w))
                return false;
        return true;
    }
};

