#include <vector>

struct Solution
{
    double probabilityOfHeads(std::vector<double>& prob, int target)
    {
        int n = prob.size();
        std::vector<std::vector<double>> f(n + 1, std::vector<double>(n + 1));
        f[0][0] = 1;
        for (auto i = 1; i <= n; i++) {
            auto p = prob[i - 1];
            f[i][0] = f[i - 1][0] * (1 - p);
            for (auto j = 1; j <= std::min(target, i); j++)
                f[i][j] = f[i - 1][j] * (1 - p) + f[i - 1][j - 1] * p;
        }
        return f[n][target];
    }
};

