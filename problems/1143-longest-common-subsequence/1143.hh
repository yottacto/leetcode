#include <string>
#include <algorithm>
#include <vector>

struct Solution
{
    int n;
    int m;
    std::vector<std::vector<int>> f;

    int longestCommonSubsequence(std::string str1, std::string str2)
    {
        n = str1.size();
        m = str2.size();
        str1 = '!' + str1;
        str2 = '!' + str2;
        f.resize(n + 1, std::vector<int>(m + 1));

        for (auto i = 1; i <= n; i++)
            for (auto j = 1; j <= m; j++) {
                f[i][j] = f[i - 1][j];
                if (f[i][j - 1] > f[i][j])
                    f[i][j] = f[i][j - 1];
                if (str1[i] == str2[j] && f[i - 1][j - 1] + 1 > f[i][j])
                    f[i][j] = f[i - 1][j - 1] + 1;
            }
        return f[n][m];
    }
};

