#include <string>
#include <vector>

auto constexpr inf = 1<<30;

struct Solution
{
    int calc(std::string const& s, int l, int r)
    {
        auto len = r - l + 1;
        auto res = 0;
        for (auto i = 0; i < len/2; i++)
            if (s[l + i] != s[r - i])
                res++;
        return res;
    }

    int palindromePartition(std::string s, int k)
    {
        int n = s.size();
        std::vector<std::vector<int>> w(n + 1, std::vector<int>(n + 1));
        for (auto i = 1; i <= n; i++)
            for (auto j = i; j <= n; j++)
                w[i][j] = calc(s, i - 1, j - 1);

        std::vector<std::vector<int>> f(n + 1, std::vector<int>(k + 1, inf));
        f[0][0] = 0;
        for (auto i = 1; i <= n; i++) {
            for (auto tk = 1; tk <= std::min(i, k); tk++) {
                for (auto j = i; j >= 1; j--) {
                    f[i][tk] = std::min(f[i][tk], f[j - 1][tk - 1] + w[j][i]);
                }
            }
        }
        return f[n][k];
    }
};

