#include <limits>
#include <cmath>

auto constexpr _max = std::numeric_limits<int>::max();
auto constexpr _min = std::numeric_limits<int>::min();

struct Solution
{
    int divide(int dividend, int divisor)
    {
        if (dividend == _min && divisor == -1)
            return _max;
        if (divisor == _min) {
            if (dividend == divisor)
                return 1;
            return 0;
        }
        if (dividend == _min) {
            if (divisor > 0)
                return divide(dividend + divisor, divisor) - 1;
            else
                return divide(dividend - divisor, divisor) + 1;
        }
        int a = std::abs(dividend);
        int b = std::abs(divisor);
        int sign = (dividend > 0) ^ (divisor > 0)
            ? -1
            : +1;
        auto res = 0;
        while (a > 0) {
            auto d = b;
            auto i = 1;
            for (; a >= d && d <= _max/2; i <<= 1)
                d <<= 1;
            if (a < d) {
                d >>= 1;
                i >>= 1;
            }
            a -= d;
            res += i;
        }
        return sign > 0 ? res : -res;
    }
};

