#include <vector>

struct Solution
{
    std::vector<int> transformArray(std::vector<int>& arr)
    {
        auto now = arr;
        auto prev = arr;
        int n = arr.size();
        bool changed;
        do {
            changed = false;
            std::swap(now, prev);
            for (auto i = 1; i < n - 1; i++) {
                now[i] = prev[i];
                if (prev[i] > prev[i - 1] && prev[i] > prev[i + 1]) {
                    now[i]--;
                    changed = true;
                } else if (prev[i] < prev[i - 1] && prev[i] < prev[i + 1]) {
                    now[i]++;
                    changed = true;
                }
            }
        } while (changed);
        return now;
    }
};

