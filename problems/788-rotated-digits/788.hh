#include <vector>
#include <algorithm>
#include <unordered_set>

struct Solution
{
    std::unordered_set<int> r_same{0, 1, 8};
    std::unordered_set<int> r_illgeal{3, 4, 7};

    int rotatedDigits(int n)
    {
        std::vector<int> a;
        for (auto tn = n; tn; tn /= 10)
            a.emplace_back(tn % 10);
        std::reverse(a.begin(), a.end());
        int l = a.size();
        // illgeal
        std::vector<std::vector<int>> f(l + 1, std::vector<int>(2));
        // lgeal
        std::vector<std::vector<int>> g(l + 1, std::vector<int>(2));
        // same
        std::vector<std::vector<int>> h(l + 1, std::vector<int>(2));

        auto res = n;
        g[0][1] = 1;
        h[0][1] = 1;
        for (auto i = 1; i <= l; i++) {
            if (r_illgeal.count(a[i - 1])) {
                f[i][1] = 1;
            } else {
                f[i][1] = f[i - 1][1];
                g[i][1] = g[i - 1][1];
            }

            if (r_same.count(a[i - 1]))
                h[i][1] = h[i - 1][1];

            f[i][0] = f[i - 1][0] * 10 + g[i - 1][0] * 3;
            g[i][0] = g[i - 1][0] * 7;
            h[i][0] = h[i - 1][0] * 3;
            for (auto j = 0; j < a[i - 1]; j++) {
                if (r_illgeal.count(j)) {
                    f[i][0] += f[i - 1][1] + g[i - 1][1];
                } else {
                    f[i][0] += f[i - 1][1];
                    g[i][0] += g[i - 1][1];
                }
                if (r_same.count(j))
                    h[i][0] += h[i - 1][1];
            }
        }

        auto count_illegal = f[l][0] + f[l][1];
        auto count_same = h[l][0] + h[l][1] - 1;
        // std::cout << count_illegal << "\n";
        // std::cout << count_same << "\n";
        return res - count_illegal - count_same;
    }
};

