#pragma once
#include <algorithm>
#include <vector>
#include <string>
#include <utility>

enum dir { down, up };

using pos_type = std::pair<int, int>;
struct data { pos_type pos; char ch; };
bool operator<(data const& a, data const& b) { return a.pos < b.pos; }

class Solution
{
    pos_type next(pos_type now, dir& d, int n)
    {
        now.first += (d == dir::down) ? 1 : -1;
        now.second++;
        if (now.first == 0    ) d = dir::down;
        if (now.first == n - 1) d = dir::up;
        return now;
    }

public:
    std::string convert(std::string s, int numRows)
    {
        if (numRows == 1) return s;
        pos_type now{0, 0};
        std::vector<data> ans;
        auto d = dir::down;
        for (auto ch : s) {
            ans.emplace_back(data{now, ch});
            now = next(now, d, numRows);
        }

        std::sort(ans.begin(), ans.end());

        for (auto i = 0u; i < s.size(); i++)
            s[i] = ans[i].ch;
        return s;
    }
};

