#include <vector>
#include <set>

struct Solution
{
    std::vector<std::vector<int>> dir{
        {-1, 0},
        {-1, +1},
        {0, +1},
        {+1, +1},
        {+1, 0},
        {+1, -1},
        {0, -1},
        {-1, -1},
    };

    bool inrange(int x, int y)
    {
        return 0 <= x && x < 8
            && 0 <= y && y < 8;
    }

    std::vector<std::vector<int>> queensAttacktheKing(std::vector<std::vector<int>>& queens, std::vector<int>& king)
    {
        std::set<std::pair<int, int>> all;
        for (auto const& q : queens)
            all.emplace(q[0], q[1]);

        std::vector<std::vector<int>> res;
        for (auto const& d : dir) {
            auto x = king[0];
            auto y = king[1];
            for (auto i = 0; i < 8; i++) {
                x += d[0];
                y += d[1];
                if (!inrange(x, y))
                    break;
                if (all.count({x, y})) {
                    res.emplace_back(std::vector<int>{x, y});
                    break;
                }
            }
        }
        return res;
    }
};

