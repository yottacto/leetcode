#pragma once
#include <algorithm>
#include <vector>
#include <utility>

auto constexpr inf = 1<<30;

struct Solution
{
    int lis(std::vector<std::pair<int, int>> const& envelopes)
    {
        std::vector<int> seq{-inf};
        for (auto const& p : envelopes) {
            auto i = p.second;
            if (seq.back() < i) {
                seq.emplace_back(i);
            } else {
                auto pos = std::lower_bound(seq.begin(), seq.end(), i) - seq.begin();
                seq[pos] = i;
            }
        }
        return seq.size() - 1;
    }

    int maxEnvelopes(std::vector<std::pair<int, int>>& envelopes)
    {
        std::sort(envelopes.begin(), envelopes.end(), [](auto const& a, auto const& b) {
            return a.first < b.first ||
                (a.first == b.first && a.second > b.second);
        });
        return lis(envelopes);
    }
};

