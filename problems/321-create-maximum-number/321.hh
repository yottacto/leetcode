// TODO
#include <vector>
#include <algorithm>

struct Solution
{
    std::vector<int> maxNumber(std::vector<int>& nums1, std::vector<int>& nums2, int k)
    {
        int n = nums1.size();
        int m = nums2.size();
        int f[n + 1][m + 1][10];
        int g[n + 1][m + 1][10];
        // 0: f[i-1][j], 1: f[i][j-1], 2: choose nums1, g[i-1][j], 3: choose nums2, g[i][j - 1]
        int ffrom[n + 1][m + 1][10];
        int gfrom[n + 1][m + 1][10];
        for (auto i = 0; i <= n; i++)
            for (auto j = 0; j <= m; j++) {
                for (auto k = 0; k < 10; k++) {
                    f[i][j][k] = 0;
                    if (i) {
                        f[i][j][k] = f[i - 1][j][k];
                        ffrom[i][j][k] = 0;
                    }
                    if (j && f[i][j - 1][k] > f[i][j][k]) {
                        f[i][j][k] = f[i][j - 1][k];
                        ffrom[i][j][k] = 1;
                    }
                }
                if (i && f[i][j][nums1[i - 1]] < g[i - 1][j][nums1[i - 1]] + 1) {
                    f[i][j][nums1[i - 1]] = g[i - 1][j][nums1[i - 1]] + 1;
                    ffrom[i][j][nums1[i - 1]] = 2;
                }
                if (j && f[i][j][nums2[j - 1]] < g[i][j - 1][nums2[j - 1]] + 1) {
                    f[i][j][nums2[j - 1]] = g[i][j - 1][nums2[j - 1]] + 1;
                    ffrom[i][j][nums2[j - 1]] = 3;
                }
                g[i][j][0] = f[i][j][0];
                gfrom[i][j][0] = 0;
                for (auto k = 1; k < 10; k++) {
                    g[i][j][k] = f[i][j][k];
                    gfrom[i][j][k] = k;
                    if (g[i][j][k] < g[i][j][k - 1]) {
                        g[i][j][k] = g[i][j][k - 1];
                        gfrom[i][j][k] = gfrom[i][j][k - 1];
                    }
                }
            }
        auto pos = 0;
        auto max = f[n][m][0];
        for (auto i = 1; i < 10; i++) {
            if (f[n][m][i] > max) {
                max = f[n][m][i];
                pos = i;
            }
        }

        std::vector<int> res;
        auto i = n;
        auto j = m;
        // 0: f[i-1][j], 1: f[i][j-1], 2: choose nums1, g[i-1][j], 3: choose nums2, g[i][j - 1]
        while (i && j) {
            if (ffrom[i][j][pos] == 0) {
                i--;
            } else if (ffrom[i][j][pos] == 1) {
                j--;
            } else if (ffrom[i][j][pos] == 2) {
                res.emplace_back(nums1[i - 1]);
                pos = gfrom[i - 1][j][nums1[i - 1]];
                i--;
            } else if (ffrom[i][j][pos] == 3) {
                res.emplace_back(nums2[j - 1]);
                pos = gfrom[i][j - 1][nums2[j - 1]];
                j--;
            }
        }

        std::reverse(res.begin(), res.end());
        return res;
    }
};

