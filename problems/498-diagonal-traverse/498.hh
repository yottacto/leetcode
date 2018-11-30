#pragma once
#include <algorithm>
#include <vector>

struct Solution
{
    std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& mat)
    {
        if (mat.empty()) return {};
        int n = mat.size();
        int m = mat[0].size();
        std::vector<int> res(n * m);
        std::generate(res.begin(), res.end(), [&, i = 0, j = 0, up = 1]() mutable {
            auto v = mat[i][j];
            if (up) {
                i--;
                j++;
                if (i < 0 || j >= m)
                    up ^= 1;
                if (j >= m) {
                    j = m - 1;
                    i += 2;
                }
                if (i < 0)
                    i = 0;
            } else {
                i++;
                j--;
                if (j < 0 || i >= n)
                    up ^= 1;
                if (i >= n) {
                    i = n - 1;
                    j += 2;
                }
                if (j < 0)
                    j = 0;
            }
            return v;
        });
        return res;
    }
};

