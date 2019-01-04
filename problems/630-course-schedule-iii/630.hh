#pragma once
#include <algorithm>
#include <vector>
#include <queue>

struct Solution
{
    int scheduleCourse(std::vector<std::vector<int>>& courses)
    {
        std::sort(courses.begin(), courses.end(), [](auto const& a, auto const& b) {
            return a[1] < b[1]
                || (a[1] == b[1] && a[0] < b[0]);
        });
        auto now = 0;
        auto count = 0;
        std::priority_queue<int> pq;
        for (auto const& i : courses) {
            if (now + i[0] <= i[1]) {
                count++;
                now += i[0];
                pq.emplace(i[0]);
            } else {
                if (!pq.empty() && pq.top() > i[0] && now - pq.top() + i[0] <= i[1]) {
                    now += i[0] - pq.top();
                    pq.pop();
                    pq.emplace(i[0]);
                }
            }
        }
        return count;
    }
};

