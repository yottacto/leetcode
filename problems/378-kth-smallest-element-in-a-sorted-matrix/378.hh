#include <vector>

struct Solution
{
    int kthSmallest(std::vector<std::vector<int>>& matrix, int k)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        auto r = 0;
        auto c = m - 1;
        while (true) {
            auto now = matrix[r][c];
            auto count_le = 0;
            auto count_lt = 0;
            auto j = m - 1;
            auto p = m - 1;
            for (auto i = 0; i < n; i++) {
                while (j >= 0 && matrix[i][j] >= now)
                    j--;
                count_lt += j + 1;
                while (p >= 0 && matrix[i][p] > now)
                    p--;
                count_le += p + 1;
            }
            if (count_le < k) {
                r++;
            } else if (count_lt >= k) {
                c--;
            } else {
                break;
            }
        }
        return matrix[r][c];
    }
};

