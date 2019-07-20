#include <vector>
#include <algorithm>

struct Solution
{
    int lengthOfLIS(std::vector<int>& a)
    {
        std::vector<int> h;
        h.reserve(a.size());
        for (auto i : a) {
            auto it = std::lower_bound(h.begin(), h.end(), i);
            if (it == h.end())
                h.emplace_back(i);
            else
                *it = i;
        }
        return h.size();
    }
};

