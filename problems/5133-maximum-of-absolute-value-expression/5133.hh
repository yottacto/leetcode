#include <vector>

struct Solution
{
    int maxAbsValExpr(std::vector<int>& a1, std::vector<int>& a2)
    {
        int n = a1.size();
        auto b = a1;
        auto c = a1;
        for (auto i = 0; i < n; i++) {
            b[i] += a2[i];
            c[i] -= a2[i];
        }
        auto t1 = b;
        auto t2 = b;
        auto t3 = c;
        auto t4 = c;
        for (auto i = 0; i < n; i++) {
            t1[i] = i + t1[i];
            t2[i] = i - t2[i];
            t3[i] = i + t3[i];
            t4[i] = i - t4[i];
        }
        auto min1 = t1[0];
        auto min2 = t2[0];
        auto min3 = t3[0];
        auto min4 = t4[0];
        auto res = -(1<<30);
        for (auto i = 0; i < n; i++) {
            min1 = std::min(min1, t1[i]);
            min2 = std::min(min2, t2[i]);
            min3 = std::min(min3, t3[i]);
            min4 = std::min(min4, t4[i]);
            res = std::max(
                res,
                std::max(
                    std::max(t1[i] - min1, t2[i] - min2),
                    std::max(t3[i] - min3, t4[i] - min4)
                )
            );
        }
        return res;
    }
};

