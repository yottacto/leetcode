#include <vector>

struct Solution
{
    int tribonacci(int n)
    {
        if (!n)
            return 0;
        if (n <= 2)
            return 1;
        std::vector<int> f(n + 1);
        f[0] = 0;
        f[1] = f[2] = 1;
        for (auto i = 3; i <= n; i++)
            f[i] = f[i - 1] + f[i - 2] + f[i - 3];
        return f[n];
    }
};

