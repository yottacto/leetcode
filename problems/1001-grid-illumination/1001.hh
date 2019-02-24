#pragma once
#include <vector>
#include <unordered_map>
#include <set>
#include <utility>

struct Solution
{
    std::unordered_map<int, int> row;
    std::unordered_map<int, int> col;
    std::unordered_map<int, int> diag0;
    std::unordered_map<int, int> diag1;

    std::vector<std::vector<int>> dir{
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1}, {0, 0}, {0, 1},
        {1, -1}, {1, 0}, {1, 1},
    };

    auto inrange(int x, int l, int r)
    {
        return l <= x && x < r;
    }

    std::vector<int> gridIllumination(int n, std::vector<std::vector<int>>& lamps, std::vector<std::vector<int>>& queries)
    {
        std::set<std::pair<int, int>> all;
        for (auto const& v : lamps) {
            all.emplace(v[0], v[1]);
            row[v[0]]++;
            col[v[1]]++;
            diag0[v[0] - v[1]]++;
            diag1[v[0] + v[1]]++;
        }
        std::vector<int> ans;
        for (auto const& v : queries) {
            if (row[v[0]] || col[v[1]] || diag0[v[0] - v[1]] || diag1[v[0] + v[1]])
                ans.emplace_back(1);
            else
                ans.emplace_back(0);
            for (auto const& d : dir) {
                auto x = v[0] + d[0];
                auto y = v[1] + d[1];
                if (inrange(x, 0, n) && inrange(y, 0, n) && all.count({x, y})) {
                    all.erase({x, y});
                    row[x]--;
                    col[y]--;
                    diag0[x - y]--;
                    diag1[x + y]--;
                }
            }

        }
        return ans;
    }
};

