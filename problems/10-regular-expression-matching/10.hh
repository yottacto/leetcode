#include <string>
#include <vector>
#include <algorithm>

struct Solution
{
    int n;
    int m;

    bool isMatch(std::string s, std::string p)
    {
        n = s.size();
        m = p.size();
        std::vector<std::vector<char>> f(n + 1, std::vector<char>(m + 1));
        f[0][0] = true;
        for (auto i = -1; i < n; i++) {
            for (auto j = 0; j < m; j++) {
                if (p[j] == '*') {
                    f[i + 1][j + 1] |= f[i + 1][j - 1];
                    if (i != -1 && (p[j - 1] == '.' || p[j - 1] == s[i]))
                        f[i + 1][j + 1] |= f[i][j + 1];
                } else if (p[j] == '.')  {
                    if (i != -1)
                        f[i + 1][j + 1] |= f[i][j];
                } else {
                    if (i != -1 && s[i] == p[j])
                        f[i + 1][j + 1] |= f[i][j];
                }
            }
        }
        return f[n][m];
    }
};

