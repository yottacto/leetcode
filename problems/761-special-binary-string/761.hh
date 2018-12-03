#pragma once
#include <string>

struct Solution
{
    int delta(char ch)
    {
        if (ch == '1') return 1;
        return -1;
    }

    bool swap(std::string& s)
    {
        int n = s.size();
        for (auto i = 0; i < n; i++) {
            auto sum = 0;
            for (auto j = i; j < n; j++) {
                sum += delta(s[j]);
                if (sum < 0) break;
                if (sum) continue;
                auto ts = 0;
                for (auto k = j + 1; k < n; k++) {
                    ts += delta(s[k]);
                    if (ts < 0) break;
                    if (ts) continue;
                    auto s1 = s.substr(i, j - i + 1);
                    auto s2 = s.substr(j + 1, k - j);
                    if (s2+s1 > s1+s2) {
                        s.erase(j + 1, k - j);
                        s.insert(i, s2);
                        return true;
                    }
                }
            }
        }
        return false;
    }

    std::string makeLargestSpecial(std::string s)
    {
        while (swap(s));
        return s;
    }
};

