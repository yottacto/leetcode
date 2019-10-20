#include <string>
#include <unordered_map>

struct Solution
{
    int balancedString(std::string s)
    {
        int n = s.size();
        std::unordered_map<char, int> count;
        for (auto ch : s)
            count[ch]++;
        auto mean = n / 4;
        auto res = n;
        auto r = 0;
        for (auto i = 0; i < n; i++) {
            while (r < n && (count['Q'] > mean || count['W'] > mean || count['E'] > mean || count['R'] > mean))
                count[s[r++]]--;
            if (count['Q'] > mean || count['W'] > mean || count['E'] > mean || count['R'] > mean)
                break;
            res = std::min(res, r - i);
            count[s[i]]++;
        }
        return res;
    }
};

