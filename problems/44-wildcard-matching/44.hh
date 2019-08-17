#include <string>

struct Solution
{
    bool isMatch(std::string s, std::string p)
    {
        int n1 = s.size();
        int n2 = p.size();
        auto i1 = 0;
        auto i2 = 0;
        auto pi1 = -1;
        auto pi2 = -1;
        while (i1 < n1) {
            if (i2 < n2 && (p[i2] == '?' || s[i1] == p[i2])) {
                i1++;
                i2++;
            } else if (i2 < n2 && p[i2] == '*') {
                pi1 = i1;
                pi2 = i2;
                i2++;
            } else if (pi2 != -1) {
                i1 = ++pi1;
                i2 = pi2 + 1;
            } else {
                return false;
            }
        }
        while (i2 < n2 && p[i2] == '*')
            i2++;
        return i2 == n2;
    }
};

