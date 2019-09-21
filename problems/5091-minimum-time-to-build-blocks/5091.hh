#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

struct Solution
{
    std::vector<int> blocks;
    int split;

    bool judge(int mid)
    {
        int n = blocks.size();
        std::unordered_map<int, int> count;
        for (auto i : blocks) {
            if (i > mid)
                return false;
            auto t = (mid - i) / split;
            count[std::min(n, t)]++;
        }

        auto now = 1;
        auto worked = 0;
        for (auto i = 0; i <= n && worked < n && now < n - worked; i++, now *= 2) {
            if (count[i] > now)
                return false;
            worked += count[i];
            now -= count[i];
        }
        return true;
    }

    int minBuildTime(std::vector<int>& blocks, int split)
    {
        this->blocks = blocks;
        this->split = split;
        auto r = 10 * split + 100007;
        auto l = 0;
        while (l + 1 < r) {
            auto mid = (l + r) / 2;
            if (judge(mid))
                r = mid;
            else
                l = mid;
        }
        if (judge(l))
            r = l;
        return r;
    }
};

