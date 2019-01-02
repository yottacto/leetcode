// actually has O(b) pre and O(1) query solution, remap blacklist number into
// unused non-blacklist number.
#pragma once
#include <algorithm>
#include <vector>
#include <random>

struct Solution
{
    int n;
    std::vector<int> bl;
    std::random_device rd{};
    std::mt19937 gen;
    std::uniform_int_distribution<> dis;

    Solution(int n, std::vector<int> const& bl)
        : n(n), bl(bl), gen(rd()), dis(0, n - bl.size() - 1)
    {
        std::sort(this->bl.begin(), this->bl.end());
        this->bl.insert(this->bl.begin(), -1);
    }

    int calc(int p)
    {
        // std::cerr << p << "\n";
        return bl[p] - p + 1;
    }

    int pick()
    {
        auto i = dis(gen);
        auto l = 0;
        auto r = (int)bl.size() - 1;
        while (l + 1 < r) {
            auto mid = (l + r) / 2;
            if (i >= calc(mid))
                l = mid;
            else
                r = mid;
        }
        if (i >= calc(r))
            l = r;
        return bl[l] + (i - calc(l) + 1);
    }
};

