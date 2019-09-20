#include <string>

struct Solution
{
    int countLetters(std::string s)
    {
        int n = s.size();
        auto res = 0;
        for (auto i = 0; i < n; i++) {
            char ch = s[i];
            for (auto j = i; j < n && s[j] == ch; j++)
                res++;
        }
        return res;
    }
};

