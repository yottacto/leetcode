#pragma once
#include <algorithm>
#include <vector>
#include <queue>

struct data
{
    data(int q, int w) : q(q), w(w), price((double)(w)/q) {}
    int q;
    int w;
    double price;
};

auto operator<(data const& a, data const& b)
{
    return a.price < b.price
        || (a.price == b.price && a.q < b.q);
}

struct Solution
{
    int sum{0};
    std::priority_queue<int> q;
    std::vector<data> a;

    double mincostToHireWorkers(
        std::vector<int>& quality,
        std::vector<int>& wage,
        int k
    )
    {
        int n = quality.size();
        a.reserve(n);
        for (auto i = 0; i < n; i++)
            a.emplace_back(quality[i], wage[i]);
        std::sort(a.begin(), a.end());
        auto ans = 1e99;
        for (auto const& i : a) {
            q.push(i.q);
            sum += i.q;
            if ((int)q.size() > k) {
                sum -= q.top();
                q.pop();
            }
            if ((int)q.size() == k)
                ans = std::min(ans, sum * i.price);
        }
        return ans;
    }
};

