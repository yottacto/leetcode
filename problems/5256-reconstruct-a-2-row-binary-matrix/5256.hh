#include <vector>

struct Solution
{
    std::vector<std::vector<int>> reconstructMatrix(int upper, int lower, std::vector<int>& colsum)
    {
        int n = colsum.size();
        std::vector<std::vector<int>> res(2, std::vector<int>(n, -1));
        auto count = 0;
        for (auto i = 0; i < n; i++) {
            if (colsum[i] == 2) {
                upper--;
                lower--;
                res[0][i] = 1;
                res[1][i] = 1;
            } else if (colsum[i] == 0) {
                res[0][i] = 0;
                res[1][i] = 0;
            } else {
                count++;
            }
        }
        if (upper < 0 || lower < 0 || upper + lower != count)
            return {};
        for (auto i = 0; i < n; i++) {
            if (res[0][i] != -1)
                continue;
            if (upper) {
                res[0][i] = 1;
                res[1][i] = 0;
                upper--;
            } else {
                res[0][i] = 0;
                res[1][i] = 1;
            }
        }
        return res;
    }
};

// 2
// 1
// [1,1,1]
// 2
// 3
// [2,2,1,1]
// 5
// 5
// [2,1,2,0,1,0,1,2,0,1]

