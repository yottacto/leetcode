#pragma once
#include <algorithm>
#include <vector>
#include <unordered_map>

struct Solution
{
    std::vector<int> next;
    std::unordered_map<int, int> last;
    int n;

    int maxChunksToSorted(std::vector<int> const& arr)
    {
        n = arr.size();
        auto a = arr;
        std::sort(a.begin(), a.end());
        next.resize(n);
        for (auto i = n - 1; i >= 0; i--) {
            if (last.count(a[i]))
                next[i] = last[a[i]];
            last[a[i]] = i;
        }

        auto r = 0;
        auto res = 0;
        for (auto i = 0; i < n; i++) {
            r = std::max(r, last[arr[i]]);
            last[arr[i]] = next[last[arr[i]]];
            if (i == r)
                res++;
        }
        return res;
    }
};

