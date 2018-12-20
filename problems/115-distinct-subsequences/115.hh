#pragma once
#include <string>
#include <vector>

struct Solution
{
    int numDistinct(std::string s, std::string t)
    {
        int n = s.size();
        int m = t.size();
        std::vector<std::vector<int>> f(n + 1, std::vector<int>(m + 1));
        f[0][0] = 1;
        for (auto i = 1; i <= n; i++) {
            f[i][0] = 1;
            for (auto j = 1; j <= m; j++) {
                f[i][j] = f[i-1][j];
                if (s[i - 1] == t[j - 1])
                    f[i][j] += f[i-1][j-1];
            }
        }
        return f[n][m];
    }
};

