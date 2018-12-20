#pragma once
#include <vector>
#include <unordered_map>

struct Solution
{
    std::vector<std::vector<char>> f;
    std::unordered_map<int, int> id;

    bool check(int i, int k, std::vector<int> const& stones)
    {
        if (!i) return k == 1;
        int p = stones[i] - k;
        if (!id.count(p)) return false;
        return f[i][id[p]];
    }

    bool canCross(std::vector<int> const& stones)
    {
        int n = stones.size();
        f.resize(n, std::vector<char>(n));
        for (auto i = 0; i < n; i++)
            id[stones[i]] = i;
        for (auto i = 1; i < n; i++) {
            f[i][0] = (stones[i] - stones[0]) == 1;
            for (auto j = 1; j < i; j++) {
                auto k = stones[i] - stones[j];
                f[i][j] = check(j, k, stones)
                    || check(j, k - 1, stones)
                    || check(j, k + 1, stones);
            }
        }
        for (auto i = 0; i < n - 1; i++)
            if (f[n - 1][i]) {
                // std::cout << i << "\n";
                return true;
            }
        return false;
    }
};

