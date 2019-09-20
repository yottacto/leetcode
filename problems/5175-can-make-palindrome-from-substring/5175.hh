#include <string>
#include <vector>

struct Solution
{
    std::vector<bool> canMakePaliQueries(std::string s, std::vector<std::vector<int>>& queries)
    {
        int n = s.size();
        std::vector<std::vector<int>> sum(n + 1, std::vector<int>(30));
        for (auto i = 0; i < n; i++) {
            for (auto ch = 'a'; ch <= 'z'; ch++) {
                sum[i + 1][ch - 'a'] = sum[i][ch - 'a'];
                if (s[i] == ch)
                    sum[i + 1][ch - 'a']++;
            }
        }
        std::vector<bool> res;
        for (auto const& q : queries) {
            auto count = 0;
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int len = r - l + 1;
            for (auto i = 0; i < 26; i++)
                if ((sum[r + 1][i] - sum[l][i]) & 1)
                    count++;
            if (len & 1)
                count--;
            res.emplace_back(count/2 <= k);
        }
        return res;
    }
};

