#include <vector>
#include <string>
#include <algorithm>

struct Solution
{
    int res{};
    int n;
    std::vector<char> ok;
    std::vector<std::vector<char>> can;
    std::vector<std::string> a;
    std::vector<int> cur;

    bool check(std::string const& s)
    {
        std::vector<char> vis(26);
        for (auto ch : s) {
            if (vis[ch - 'a'])
                return false;
            vis[ch - 'a'] = true;
        }
        return true;
    }

    void dfs(int d, int len)
    {
        if (d == n) {
            res = std::max(res, len);
            return;
        }
        dfs(d + 1, len);
        if (ok[d]) {
            for (auto i : cur)
                if (!can[i][d])
                    return;
            cur.emplace_back(d);
            dfs(d + 1, len + a[d].size());
            cur.pop_back();
        }
    }

    int maxLength(std::vector<std::string>& a)
    {
        n = a.size();
        this->a = a;
        ok.resize(n);
        can.resize(n, std::vector<char>(n));
        for (auto i = 0; i < n; i++)
            ok[i] = check(a[i]);
        for (auto i = 0; i < n; i++)
            for (auto j = i + 1; j < n; j++) {
                can[i][j] = can[j][i] = check(a[i] + a[j]);
            }
        dfs(0, 0);
        return res;
    }
};

