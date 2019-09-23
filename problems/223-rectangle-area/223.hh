#include <algorithm>

struct Solution
{
    int area(int a, int b, int c, int d)
    {
        return (c - a) * (d - b);
    }

    int common_length(int a, int c, int e, int g)
    {
        if (c <= e || a >= g)
            return 0;
        return std::min(c, g) - std::max(a, e);
    }

    int computeArea(int a, int b, int c, int d, int e, int f, int g, int h)
    {
        return area(a, b, c, d)
            - common_length(a, c, e, g) * common_length(b, d, f, h)
            + area(e, f, g, h);
    }
};

