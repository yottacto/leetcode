#pragma once
#include <vector>
#include <queue>
#include <unordered_map>

struct _data
{
    int num;
    int count;
};

struct Solution
{
    int n;

    std::vector<int> rearrangeBarcodes(std::vector<int>& barcodes)
    {
        n = barcodes.size();
        std::unordered_map<int, int> um;
        for (auto i : barcodes)
            um[i]++;
        std::vector<int> res(n);
        auto cmp = [](_data const& a, _data const& b) {
            return a.count < b.count;
        };
        std::priority_queue<_data, std::vector<_data>, decltype(cmp)> pq(cmp);
        for (auto const& p : um)
            pq.emplace(_data{p.first, p.second});
        auto start = 0;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            for (auto i = 0; i < top.count; i++)
                res[start + 2 * i] = top.num;
            start++;
            for (auto i = 0; i < top.count - 1; i++, start += 2) {
                auto now = pq.top();
                pq.pop();
                res[start] = now.num;
                now.count--;
                pq.emplace(now);
            }
        }
        return res;
    }
};

