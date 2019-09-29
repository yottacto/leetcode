#include <string>
#include <vector>
#include <cmath>

struct Solution
{
    int equalSubstring(std::string s, std::string t, int maxCost)
    {
        int n = s.size();
        std::vector<int> dis(n);
        for (auto i = 0; i < n; i++)
            dis[i] = std::abs(s[i] - t[i]);
        auto res = 0;
        auto j = 0;
        auto sum = 0;
        for (auto i = 0; i < n; i++) {
            while (j < n && sum + dis[j] <= maxCost) {
                sum += dis[j];
                j++;
            }
            res = std::max(res, j - i);
            sum -= dis[i];
        }
        return res;
    }
};

