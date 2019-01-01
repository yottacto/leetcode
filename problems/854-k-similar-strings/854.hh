// nice dp (decompose graph into as many as possible circles), or bfs (optimize
// with greedy match, every time match at least one).
// the standard solution's complexity about dp seems not correct.
#pragma once
#include <algorithm>
#include <vector>
#include <string>

struct Solution
{
    int kSimilarity(std::string a, std::string b)
    {
        int n = a.size();
        for (auto i = 0; i < n; i++) {
            if (a[i] == b[i])
                continue;
            std::vector<int> matches;
            for (auto j = i + 1; j < n; j++) {
                if (a[j] == b[i] && a[j] != b[j]) {
                    matches.emplace_back(j);
                    if (a[i] == b[j]) {
                        std::swap(a[i], a[j]);
                        return 1 + kSimilarity(a.substr(i + 1), b.substr(i + 1));
                    }
                }
            }
            auto best = n;
            for (auto j : matches) {
                std::swap(a[i], a[j]);
                best = std::min(best, 1 + kSimilarity(a.substr(i + 1), b.substr(i + 1)));
                std::swap(a[i], a[j]);
            }
            return best;
        }
        return 0;
    }
};

