#pragma once
#include <vector>
#include <algorithm>

struct Solution
{
    std::vector<double> sampleStats(std::vector<int>& count)
    {
        double min = 255;
        double max = 0;
        double sum = 0;
        double mode = -1;
        auto max_count = 0;
        auto tot = 0;
        for (auto i = 0; i <= 255; i++)
            if (count[i]) {
                min = std::min<double>(min, i);
                max = std::max<double>(max, i);
                sum += count[i] * i;
                if (count[i] > max_count) {
                    max_count = count[i];
                    mode = i;
                }
                tot += count[i];
            }
        double avg = sum / tot;
        auto now = 0;
        double median = 0;
        for (auto i = 0; i <= 255; i++) {
            if (count[i]) {
                if (now == tot/2) {
                    median += i;
                    break;
                } else if (now < tot/2 && now + count[i] > tot/2) {
                    median += 2 * i;
                    break;
                } else if (now < tot/2 && now + count[i] == tot/2) {
                    median += i;
                }
                now += count[i];
            }
        }
        median /= 2;
        return {min, max, avg, median, mode};
    }
};

