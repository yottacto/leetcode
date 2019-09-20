#include <algorithm>

struct Solution
{
    int maximumNumberOfOnes(int m, int n, int l, int count)
    {
        int a = n / l;
        int ra = n % l;
        int b = m / l;
        int rb = m % l;
        if (a > b)
            return maximumNumberOfOnes(n, m, l, count);
        auto res = a * b * count + std::min(count, ra * rb) * (a + b + 1);
        if (count <= ra * rb) {
        } else if (count <= ra * l) {
            auto remain = count - ra * rb;
            res += b * remain;
        } else {
            res += b * (l - rb) * ra;
            auto remain = count - l * ra;
            remain = std::min(remain, rb * (l - ra));
            res += a * remain;
        }
        return res;
    }
};

