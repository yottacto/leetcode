#include <algorithm>
#include <vector>
#include <string>

// O(alpha * n), two pointer
struct Solution
{
    int longestSubstring(std::string s, int k)
    {
        int n = s.size();
        std::unordered_map<char, int> count;
        auto res = 0;
        for (auto unique = 1; unique <= 26; unique++) {
            auto j = 0;
            int tot_diff = 0;
            int reach_k = 0;
            for (auto i = 0; i < n; i++) {
                while (
                    j < n && (
                        tot_diff < unique
                        || (tot_diff == unique && count.count(s[j]))
                    )
                ) {
                    if (!count.count(s[j]))
                        tot_diff++;
                    count[s[j]]++;
                    if (count[s[j]] == k)
                        reach_k++;
                    j++;
                }
                if (reach_k == tot_diff)
                    res = std::max(res, j - i);
                if (count[s[i]] == k)
                    reach_k--;
                count[s[i]]--;
                if (!count[s[i]]) {
                    tot_diff--;
                    count.erase(s[i]);
                }
            }
        }
        return res;
    }
};

// O(nlogn)
// struct Solution
// {
//     int longestSubstring(std::string s, int k)
//     {
//         std::vector<int> count(26);
//         for (auto ch : s)
//             count[ch - 'a']++;
//         int n = s.size();
//         auto res = 0;
//         auto last = 0;
//         for (auto i = 0; i < n; i++) {
//             if (count[s[i] - 'a'] < k) {
//                 res = std::max(res, longestSubstring(s.substr(last, i - last), k));
//                 last = i + 1;
//             }
//         }
//         if (last < n) {
//             if (!last)
//                 res = n;
//             else
//                 res = std::max(res, longestSubstring(s.substr(last, n - last), k));
//         }
//         return res;
//     }
// };

