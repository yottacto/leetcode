#pragma once
#include <string>
#include <map>
#include <vector>

struct Solution
{
    std::map<int, std::vector<char>> table{
        {0, {'I', 'V', 'X'}},
        {1, {'X', 'L', 'C'}},
        {2, {'C', 'D', 'M'}},
        {3, {'M'}}
    };
    std::vector<int> div{1, 10, 100, 1000};

    std::string trans(int x, int level)
    {
        if (!x) return "";
        if (x <= 3) return std::string(x, table[level][0]);
        if (x == 4) return {table[level][0], table[level][1]};
        if (x == 5) return {table[level][1]};
        if (x <= 8) return table[level][1] + std::string(x - 5, table[level][0]);
        return {table[level][0], table[level][2]};
    }

    std::string intToRoman(int num)
    {
        std::string res;
        for (auto i = 3; i >= 0; i--)
            res += trans((num / div[i]) % 10, i);
        return res;
    }
};

