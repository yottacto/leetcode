#include <vector>
#include <unordered_map>

struct Solution
{
    int longestSubsequence(std::vector<int>& a, int diff)
    {
        int n = a.size();
        std::vector<int> len(n, 1);
        std::unordered_map<int, int> last_pos;
        auto res = 0;
        for (auto i = 0; i < n; i++) {
            auto p = a[i] - diff;
            if (last_pos.count(p))
                len[i] = len[last_pos[p]] + 1;
            last_pos[a[i]] = i;
            res = std::max(res, len[i]);
        }
        return res;
    }
};

