#include <string>
#include <vector>

struct Solution
{
    int longestPalindromeSubseq(std::string s)
    {
        int l = s.size();
        std::vector<std::vector<int>> f(l + 2, std::vector<int>(l + 2));
        for (auto len = 1; len <= l; len++)
            for (auto i = 1; i + len - 1 <= l; i++) {
                auto j = i + len - 1;
                f[i][j] = std::max(f[i + 1][j], f[i][j - 1]);
                if (s[i - 1] == s[j - 1])
                    f[i][j] = std::max(f[i][j], f[i + 1][j - 1] + 2 - (i == j));
            }
        return f[1][l];
    }
};

