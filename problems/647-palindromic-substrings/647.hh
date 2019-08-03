#include <string>
#include <vector>

struct Solution
{
    int countSubstrings(std::string s)
    {
        std::string t{"!#"};
        for (auto ch : s) {
            t += ch;
            t += '#';
        }
        t += '~';
        int l = t.size() - 2;
        std::vector<int> p(l + 1);
        auto r = 0;
        auto c = -1;
        auto res = 0;
        for (auto i = 1; i <= l; i++) {
            if (i < r)
                p[i] = std::min(p[2 * c - i], r - i);
            while (t[i - p[i]] == t[i + p[i]])
                p[i]++;
            if (r < i + p[i]) {
                r = i + p[i];
                c = i;
            }
            auto len = (2 * p[i] - 1) / 2;
            res += (len + 1) / 2;
        }
        return res;
    }
};

