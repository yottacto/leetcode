#include <string>
#include <cmath>

struct Solution
{
    int calculateTime(std::string keyboard, std::string word)
    {
        int pos[30];
        for (auto i = 0; i < 26; i++)
            pos[keyboard[i] - 'a'] = i;
        auto res = pos[word[0] - 'a'];
        int n = word.size();
        for (auto i = 1; i < n; i++)
            res += std::abs(pos[word[i] - 'a'] - pos[word[i - 1] - 'a']);
        return res;
    }
};

