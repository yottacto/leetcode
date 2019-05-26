#pragma once
#include <vector>
#include <algorithm>
#include <stack>

struct Solution
{
    int n;

    std::vector<int> prevPermOpt1(std::vector<int>& a)
    {
        n = a.size();
        std::stack<int> q;
        auto t_pos = -1;
        auto t_value = -1;
        auto value_pos = -1;
        for (auto i = 0; i < n; i++) {
            while (!q.empty() && a[i] >= a[q.top()])
                q.pop();
            if (!q.empty()) {
                auto t = q.top();
                // std::cout << i << " t=" << t << " " << a[i] << "\n";
                if (t > t_pos) {
                    t_pos = t;
                    t_value = a[i];
                    value_pos = i;
                } else if (t == t_pos) {
                    if (a[i] > t_value) {
                        t_value = a[i];
                        value_pos = i;
                    } else if (a[i] == t_value) {
                        t_value = a[i];
                        value_pos = i;
                    }
                }
            }
            q.emplace(i);
        }
        if (value_pos != -1)
            std::swap(a[value_pos], a[t_pos]);
        return a;
    }
};

// [3,2,1]
// [1,1,5]
// [1,9,4,6,7]
// [3,1,1,3]

