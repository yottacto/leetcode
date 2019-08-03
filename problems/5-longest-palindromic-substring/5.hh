#include <string>
#include <vector>

struct Solution
{
    std::string longestPalindrome(std::string s)
    {
        std::string t{"!#"};
        for (auto ch : s) {
            t += ch;
            t += '#';
        }
        t += '~';
        int len = t.size() - 2;
        std::vector<int> p(len + 1);
        auto r = 0;
        auto c = -1;
        auto max_len = 0;
        auto pos = -1;
        for (auto i = 1; i <= len; i++) {
            if (i < r)
                p[i] = std::min(r - i, p[2 * c - 1]);
            while (t[i - p[i]] == t[i + p[i]])
                p[i]++;
            if (i + p[i] > r) {
                r = i + p[i];
                c = i;
            }
            if (p[i] > max_len) {
                max_len = p[i];
                pos = i;
            }
        }
        auto l = (pos - max_len + 1) / 2;
        return s.substr(l, (max_len * 2 - 1) / 2);
    }
};

