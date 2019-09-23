#include <algorithm>
#include <string>
#include <vector>

struct Solution
{
    int n;
    int m;
    std::vector<std::vector<int>> f;
    std::vector<std::vector<int>> from;
    std::string str1;
    std::string str2;

    std::string construct()
    {
        std::string res;
        auto i = n;
        auto j = m;
        while (i && j) {
            if (from[i][j] == 0) {
                i--;
            } else if (from[i][j] == 1) {
                j--;
            } else {
                res += str1[i];
                i--;
                j--;
            }
        }
        std::reverse(res.begin(), res.end());
        return res;
    }

    std::string shortestCommonSupersequence(std::string str1, std::string str2)
    {
        n = str1.size();
        m = str2.size();
        str1 = '!' + str1;
        str2 = '!' + str2;
        this->str1 = str1;
        this->str2 = str2;
        f.resize(n + 1, std::vector<int>(m + 1));
        // 0: [i - 1][j], 1: [i][j - 1], 2: [i - 1][j - 1]
        from.resize(n + 1, std::vector<int>(m + 1));

        for (auto i = 1; i <= n; i++)
            for (auto j = 1; j <= m; j++) {
                f[i][j] = f[i - 1][j];
                if (f[i][j - 1] > f[i][j]) {
                    f[i][j] = f[i][j - 1];
                    from[i][j] = 1;
                }
                if (str1[i] == str2[j] && f[i - 1][j - 1] + 1 > f[i][j])  {
                    f[i][j] = f[i - 1][j - 1] + 1;
                    from[i][j] = 2;
                }
            }

        auto lcs = construct();
        // std::cout << "[lcs] = " << lcs << "\n";
        std::string res;
        auto i = 1;
        auto j = 1;
        lcs += '!';
        for (auto ch : lcs) {
            while (i <= n && str1[i] != ch)
                res += str1[i++];
            while (j <= m && str2[j] != ch)
                res += str2[j++];
            if (ch != '!')
                res += ch;
            i++;
            j++;
        }
        return res;
    }
};

