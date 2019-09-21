#include <utility>
#include <cmath>
#include <queue>

struct _hash
{
    size_t operator()(std::pair<int, int> const& a) const
    {
        auto h1 = std::hash<int>{}(a.first);
        auto h2 = std::hash<int>{}(a.second);
        return h1 * 31 + h2;
    }
};

struct Solution
{
    using pair_type = std::pair<int, int>;
    int dis[1000][1000] = {};

    std::vector<std::vector<int>> dir {
        {-2, -1},
        {-2, 1},
        {-1, 2},
        {1, 2},
        {2, 1},
        {2, -1},
        {1, -2},
        {-1, -2},
    };

    int minKnightMoves(int x, int y)
    {
        dis[400][400] = 1;
        std::queue<pair_type> q;
        q.emplace(0, 0);
        while (!q.empty()) {
            auto now = q.front();
            if (now == pair_type{x, y})
                return dis[now.first + 400][now.second + 400] - 1;
            q.pop();
            for (auto const& d : dir) {
                auto nx = now.first + d[0];
                auto ny = now.second + d[1];
                if (std::abs(nx) > 310 || std::abs(ny) > 310)
                    continue;
                if (dis[nx + 400][ny + 400])
                    continue;
                dis[nx + 400][ny + 400] = dis[now.first + 400][now.second + 400] + 1;
                q.emplace(nx, ny);
            }
        }
        return -1;
    }
};

