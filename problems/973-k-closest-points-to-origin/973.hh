#include <vector>
#include <algorithm>
#include <queue>
#include <random>

struct Solution
{
    using point_type = std::vector<int>;

    std::random_device rd{};
    std::mt19937 gen{rd()};

    int distance(std::vector<int> const& p)
    {
        return p[0] * p[0] + p[1] * p[1];
    }

    void quick(std::vector<point_type>& points, int start, int end, int k)
    {
        if (k == end - start)
            return;
        std::uniform_int_distribution<> dis(start, end - 1);
        // auto pivot = distance(points[start]);
        auto pivot = distance(points[dis(gen)]);
        auto i = start;
        auto j = end - 1;
        while (i <= j) {
            while (distance(points[i]) < pivot)
                i++;
            while (distance(points[j]) > pivot)
                j--;
            if (i <= j) {
                std::swap(points[i], points[j]);
                i++;
                j--;
            }
        }
        auto left = i - start;
        if (k <= left) {
            quick(points, start, i, k);
        } else {
            quick(points, i, end, k - left);
        }
    }

    std::vector<point_type> kClosest(std::vector<point_type>& points, int k)
    {
        int n = points.size();
        quick(points, 0, n, k);
        std::vector<point_type> res;
        res.reserve(k);
        for (auto i = 0; i < k; i++)
            res.emplace_back(points[i]);
        return res;
    }
};

