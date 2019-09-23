#include <vector>
#include <queue>

struct _data
{
    int v;
    int p;
};

// bool operator<(_data const& a, data const& b)
// {
//     return a.v > b.v;
// }

struct Solution
{
    int nthSuperUglyNumber(int n, std::vector<int>& primes)
    {
        int k = primes.size();
        std::vector<int> res;
        res.reserve(n);
        res.emplace_back(1);
        std::vector<int> pos(k, 0);
        auto cmp = [](auto const& a, auto const& b) {
            return a.v > b.v;
        };
        std::priority_queue<_data, std::vector<_data>, decltype(cmp)> pq{cmp};
        for (auto i = 0; i < k; i++)
            pq.emplace(_data{primes[i], i});
        for (; (int)res.size() < n; ) {
            while (!pq.empty() && pq.top().v <= res.back()) {
                auto [v, p] = pq.top();
                pq.pop();
                pos[p]++;
                pq.emplace(_data{res[pos[p]] * primes[p], p});
            }
            auto [v, p] = pq.top();
            pq.pop();
            res.emplace_back(v);
            pos[p]++;
            pq.emplace(_data{res[pos[p]] * primes[p], p});
        }
        return res.back();
    }
};

