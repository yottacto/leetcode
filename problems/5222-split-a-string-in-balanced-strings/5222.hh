#include <string>
#include <unordered_map>

struct Solution
{
    int balancedStringSplit(std::string s)
    {
        std::unordered_map<char, int> table{
            {'L', +1},
            {'R', -1},
        };
        auto sum = 0;
        auto res = 0;
        for (auto ch : s) {
            sum += table[ch];
            if (!sum)
                res++;
        }
        return res;
    }
};

