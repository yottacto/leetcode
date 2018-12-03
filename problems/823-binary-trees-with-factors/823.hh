#pragma once
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>

using ll = long long;
auto constexpr mo = 1000000007ll;

struct Solution
{
    auto add(ll x, ll y) { return (x + y) % mo; }
    auto mul(ll x, ll y) { return (x * y) % mo; }

    int numFactoredBinaryTrees(std::vector<int> const& a)
    {
        std::set<int> count(a.begin(), a.end());
        std::unordered_map<int, ll> f;
        auto res = 0ll;
        for (auto i : count) {
            f[i] = 1;
            for (auto j : count) {
                if (j * j > i)
                    break;
                if (i % j == 0 && count.count(i/j)) {
                    auto tmp = mul(f[j], f[i/j]);
                    f[i] = add(f[i], tmp);
                    if (i/j != j)
                        f[i] = add(f[i], tmp);
                }
            }
            res = add(res, f[i]);
        }
        return res;
    }
};

