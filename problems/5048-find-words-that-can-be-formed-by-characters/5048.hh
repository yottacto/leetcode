#include <vector>
#include <string>
#include <unordered_map>

struct Solution
{
    int countCharacters(std::vector<std::string>& words, std::string chars)
    {
        std::unordered_map<char, int> count;
        for (auto ch : chars)
            count[ch]++;
        auto res = 0;
        for (auto const& s : words) {
            if ([&]() {
                auto tcount = count;
                for (auto ch : s) {
                    if (!tcount[ch])
                        return false;
                    tcount[ch]--;
                }
                return true;
            }())
                res += s.size();

        }
        return res;
    }
};

