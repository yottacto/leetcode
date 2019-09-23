#include <string>
#include <vector>
#include <algorithm>

struct Solution
{
    bool buddyStrings(std::string a, std::string b)
    {
        if (a.size() != b.size())
            return false;
        int n = a.size();
        std::vector<int> diff;
        std::vector<int> count(26);
        for (auto i = 0; i < n; i++) {
            count[a[i] - 'a']++;
            if (a[i] != b[i]) {
                if (diff.size() < 2)
                    diff.emplace_back(i);
                else
                    return false;
            }
        }
        if (diff.size() == 1)
            return false;
        if (diff.size() == 2)
            return a[diff[0]] == b[diff[1]]
                && a[diff[1]] == b[diff[0]];
        return std::any_of(count.begin(), count.end(), [](auto x) {
            return x > 1;
        });
    }
};

