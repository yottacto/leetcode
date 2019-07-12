#pragma once
#include <vector>
#include <map>

struct Solution
{
    int maxEqualRowsAfterFlips(std::vector<std::vector<int>>& matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        std::map<std::string, int> count;
        auto res = 0;
        for (auto i = 0; i < n; i++) {
            std::string s{"0"};
            auto rev = matrix[i][0] == 1;
            for (auto j = 1; j < m; j++) {
                if (!rev)
                    s += char('0' + matrix[i][j]);
                else
                    s += char('0' + 1 - matrix[i][j]);
            }
            count[s]++;
            if (count[s] > res)
                res = count[s];
        }
        return res;
    }
};

