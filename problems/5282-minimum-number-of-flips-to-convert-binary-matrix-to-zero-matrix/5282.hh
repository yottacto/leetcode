#include <vector>
#include <algorithm>

auto constexpr inf = 1<<30;

struct Solution
{
    std::vector<std::vector<int>> a;
    std::vector<std::vector<int>> dir{
        {-1, 0}, {1, 0},
        {0, -1}, {0, 1},
    };
    int n;
    int m;

    bool inrange(int x, int y)
    {
        return (0 <= x && x < n)
            && (0 <= y && y < m);
    }

    void filp(int x, int y, std::vector<std::vector<int>>& a)
    {
        a[x][y] ^= 1;
        for (auto const& d : dir) {
            auto nx = x + d[0];
            auto ny = y + d[1];
            if (inrange(nx, ny))
                a[nx][ny] ^= 1;
        }
    }

    bool all_zero(std::vector<std::vector<int>>& a)
    {
        for (auto i = 0; i < n; i++)
            for (auto j = 0; j < m; j++)
                if (a[i][j])
                    return false;
        return true;
    }

    int check(int st)
    {
        auto b = a;
        auto count = 0;
        for (auto i = 0; i < n; i++)
            for (auto j = 0; j < m; j++) {
                auto p = i * m + j;
                if (st & (1<<p)) {
                    count++;
                    filp(i, j, b);
                }
            }
        if (all_zero(b))
            return count;
        return inf;
    }

    int minFlips(std::vector<std::vector<int>>& mat)
    {
        a = mat;
        n = mat.size();
        m = mat[0].size();
        auto res = inf;
        for (auto i = 0; i < (1<<(m * n)); i++)
            res = std::min(res, check(i));
        if (res == inf)
            res = -1;
        return res;
    }
};

