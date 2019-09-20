#include <string>
#include <unordered_map>

struct Solution
{
    int maxNumberOfBalloons(std::string text)
    {
        std::unordered_map<char, int> count;
        for (auto ch : text)
            count[ch]++;
        std::string ball{"balloon"};
        std::unordered_map<char, int> count2;
        for (auto ch : ball)
            count2[ch]++;
        auto res = 0;
        while (true) {
            for (auto const& p : count2) {
                if (count[p.first] < p.second)
                    return res;
                count[p.first] -= p.second;
            }
            res++;
        }
        return res;
    }
};

