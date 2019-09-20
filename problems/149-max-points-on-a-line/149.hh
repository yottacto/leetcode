#include <vector>
#include <unordered_map>
#include <functional>
#include <cmath>

struct Solution
{

struct data
{
    data(int x, int y)
        : a(x), b(y)
    {
        if (!x && !y) {
            return;
        }
        if (!y) {
            a = 0;
            b = 1;
            return;
        }
        if (!x) {
            a = 1;
            b = 0;
            return;
        }
        sign = (x > 0) ^ (y > 0) ? -1 : +1;
        a = std::abs(a);
        b = std::abs(b); auto g = gcd(a, b);
        a /= g;
        b /= g;
    }

    int gcd(int x, int y)
    {
        return !y ? x : gcd(y, x % y);
    }

    bool operator==(data const& other) const
    {
        return sign == other.sign
            && a == other.a
            && b == other.b;
    }


    // k = a / b
    int sign{1};
    int a;
    int b;
};

    int maxPoints(std::vector<std::vector<int>>& points)
    {
        auto hasher = [](data const& d) {
            std::size_t res = 17;
            res = 31 * res + std::hash<int>()(d.sign);
            res = 31 * res + std::hash<int>()(d.a);
            res = 31 * res + std::hash<int>()(d.b);
            return res;
        };
        auto res = 0;
        for (auto i = 0u; i < points.size(); i++) {
            std::unordered_map<data, int, decltype(hasher)> count(17, hasher);
            auto max = 0;
            for (auto j = 0u; j < points.size(); j++) {
                data d(points[i][1] - points[j][1], points[i][0] - points[j][0]);
                count[d]++;
                if (d == data(0, 0))
                    continue;
                max = std::max(max, count[d]);
            }
            res = std::max(res, max + count[data(0, 0)]);
        }
        return res;
    }
};

