#include <string>
#include <algorithm>

struct Solution
{
    int minimumSwap(std::string s1, std::string s2)
    {
        int n = s1.size();
        int count[2] = {};
        for (auto i = 0; i < n; i++) {
            if (s1[i] == s2[i])
                continue;
            count[s1[i] == 'x']++;
        }
        auto res = count[0] / 2 + count[1] / 2;
        count[0] %= 2;
        count[1] %= 2;
        if (count[0] ^ count[1])
            return -1;
        if (count[0] && count[1])
            res += 2;
        return res;
    }
};

