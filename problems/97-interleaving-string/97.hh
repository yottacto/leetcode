#include <algorithm>
#include <string>
#include <vector>

struct Solution
{
    bool isInterleave(std::string s1, std::string s2, std::string s3)
    {
        if (s1.size() + s2.size() != s3.size())
            return false;
        int n = s1.size();
        int m = s2.size();
        std::vector<std::vector<int>> f(2, std::vector<int>(m + 1));
        auto now = 1;
        auto prev = 0;
        f[prev][0] = true;
        for (auto i = 0; i <= n; i++) {
            std::swap(now, prev);
            for (auto j = 0; j <= m; j++) {
                if (i + j) {
                    f[now][j] = false;
                    if (i && s3[i + j - 1] == s1[i - 1])
                        f[now][j] |= f[prev][j];
                    if (j && s3[i + j - 1] == s2[j - 1])
                        f[now][j] |= f[now][j - 1];
                }
            }
        }
        return f[now][m];
    }
};

