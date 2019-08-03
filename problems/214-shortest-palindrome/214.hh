#include <algorithm>
#include <string>
#include <vector>

struct Solution
{
    std::string shortestPalindrome(std::string s)
    {
        std::string t{"!#"};
        for (auto ch : s) {
            t += ch;
            t += '#';
        }
        t += '~';
        int len = t.size() - 2;
        int r = 0;
        int c = -1;
        std::vector<int> p(len + 1);
        auto max = 1;
        for (auto i = 1; i <= len; i++) {
            if (i < r)
                p[i] = std::min(p[2 * c - i], r - i);
            while (t[i - p[i]] == t[i + p[i]])
                p[i]++;
            if (r < i + p[i]) {
                r = i + p[i];
                c = i;
            }
            if (i - p[i] == 0)
                max = (2 * p[i] - 1) / 2;
        }
        auto add = s.substr(max);
        std::reverse(add.begin(), add.end());
        return add + s;
    }
};

