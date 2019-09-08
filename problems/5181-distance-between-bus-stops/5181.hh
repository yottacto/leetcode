#include <vector>

struct Solution
{
    int distanceBetweenBusStops(std::vector<int>& distance, int start, int destination)
    {
        int n = distance.size();
        std::vector<int> d(2 * n);
        auto sum = 0;
        for (auto i = 0; i < n; i++) {
            d[i] = d[i + n] = distance[i];
            sum += d[i];
        }
        auto res = 0;
        if (destination < start)
            destination += n;
        for (auto i = start; i < destination; i++)
            res += d[i];
        return std::min(res, sum - res);
    }
};

