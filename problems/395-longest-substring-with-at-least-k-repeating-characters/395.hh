#include <algorithm>
#include <vector>
#include <string>

struct Solution
{
    int longestSubstring(std::string s, int k)
    {
        std::vector<int> count(26);
        for (auto ch : s)
            count[ch - 'a']++;
        int n = s.size();
        auto res = 0;
        auto last = 0;
        for (auto i = 0; i < n; i++) {
            if (count[s[i] - 'a'] < k) {
                res = std::max(res, longestSubstring(s.substr(last, i - last), k));
                last = i + 1;
            }
        }
        if (last < n) {
            if (!last)
                res = n;
            else
                res = std::max(res, longestSubstring(s.substr(last, n - last), k));
        }
        return res;
    }
};

