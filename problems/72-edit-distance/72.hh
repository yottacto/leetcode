#pragma once
#include <algorithm>
#include <string>

auto constexpr inf = 1<<30;

struct Solution
{
    int minDistance(std::string word1, std::string word2)
    {
        int n = word1.size();
        int m = word2.size();
        int f[n + 1][m + 1];
        for (auto i = 0; i <= n; i++)
            for (auto j = 0; j <= m; j++)
                f[i][j] = inf;

        f[0][0] = 0;
        for (auto i = 1; i <= m; i++)
            f[0][i] = i;
        for (auto i = 1; i <= n; i++)
            f[i][0] = i;
        for (auto i = 1; i <= n; i++)
            for (auto j = 1; j <= m; j++) {
                // insert
                f[i][j] = f[i][j - 1] + 1;
                // delete
                f[i][j] = std::min(f[i][j], f[i - 1][j] + 1);
                // replace
                f[i][j] = std::min(f[i][j], f[i - 1][j - 1] + 1);
                // direct match
                if (word1[i - 1] == word2[j - 1])
                    f[i][j] = std::min(f[i][j], f[i - 1][j - 1]);
            }

        return f[n][m];
    }
};

