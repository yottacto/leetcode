#include <vector>
#include <queue>
#include <functional>

struct _data
{
    int x;
    int y;
    // 0: right, 1: down, 2: left, 3: up
    int d;
};

struct Solution
{
    int minimumMoves(std::vector<std::vector<int>>& grid)
    {
        int dis[200][200][4];
        int n = grid.size();
        for (auto i = 0; i <= n; i++)
            for (auto j = 0; j <= n; j++)
                for (auto d = 0; d < 4; d++)
                    dis[i][j][d] = -1;
        dis[0][0][0] = 0;
        std::queue<_data> q;
        q.emplace(_data{0, 0, 0});

        auto inrange = [&](_data const& now) -> bool {
            return 0 <= now.x && now.x < n
                && 0 <= now.y && now.y < n;
        };

        auto head = [&](_data const& now) -> _data {
            _data res = now;
            if (now.d == 0)
                res.y += 1;
            else if (now.d == 1)
                res.x += 1;
            else if (now.d == 2)
                res.y -= 1;
            else
                res.x -= 1;
            return res;
        };

        auto dir = [&](_data const& now) -> _data {
            _data res = now;
            if (now.d == 0) {
                res.x += 1;
                res.y += 1;
            } else if (now.d == 1) {
                res.x += 1;
                res.y -= 1;
            } else if (now.d == 2) {
                res.x -= 1;
                res.y -= 1;
            } else {
                res.x -= 1;
                res.y += 1;
            }
            return res;
        };

        auto left = [&](_data const& now, _data& next) -> bool {
            if (now.d == 2) return false;
            if (now.d == 0 || now.d == 2) {
                auto d = 1;
                next.x = now.x;
                next.y = now.y + d;
                next.d = now.d;
                if (!inrange(head(next)) || grid[head(next).x][head(next).y] == 1)
                    return false;
            } else {
                auto d = 1;
                next.x = now.x;
                next.y = now.y + d;
                next.d = now.d;
                if (!inrange(next) || grid[next.x][next.y] == 1
                        || grid[head(next).x][head(next).y] == 1)
                    return false;
            }
            return true;
        };
        auto down = [&](_data const& now, _data& next) -> bool {
            if (now.d == 3) return false;
            if (now.d == 0 || now.d == 2) {
                auto d = 1;
                next.x = now.x + d;
                next.y = now.y;
                next.d = now.d;
                if (!inrange(next) || grid[next.x][next.y] == 1
                        || grid[head(next).x][head(next).y] == 1)
                    return false;
            } else {
                auto d = 1;
                next.x = now.x + d;
                next.y = now.y;
                next.d = now.d;
                if (!inrange(head(next)) || grid[head(next).x][head(next).y] == 1)
                    return false;
            }
            return true;
        };
        auto rotate_clockwise = [&](_data const& now, _data& next) -> bool {
            next = now;
            next.d = (next.d + 1) % 4;
            if (!inrange(head(next)) || !inrange(dir(now))
                    || grid[head(next).x][head(next).y] == 1
                    || grid[dir(now).x][dir(now).y] == 1)
                return false;
            return true;
        };
        auto rotate_couter_clockwise = [&](_data const& now, _data& next) -> bool {
            next = now;
            next.d = (next.d - 1 + 4) % 4;
            if (!inrange(head(next)) || !inrange(dir(next))
                    || grid[head(next).x][head(next).y] == 1
                    || grid[dir(next).x][dir(next).y] == 1)
                return false;
            return true;
        };
        std::vector<std::function<bool(_data const&, _data&)>> all{
            left, down, rotate_clockwise, rotate_couter_clockwise,
        };
        while (!q.empty()) {
            auto now = q.front();
            // std::cout << now.x << " "  << now.y << " " << now.d << "\n";
            q.pop();
            auto dnow = dis[now.x][now.y][now.d];
            for (auto const& p : all) {
                _data next;
                if (p(now, next)) {
                    // if (next.x == 5 && next.y == 3 && next.d == 1)
                    //     std::cout << now.x << " "  << now.y << " " << now.d << "\n";
                    if (dis[next.x][next.y][next.d] == -1) {
                        dis[next.x][next.y][next.d] = dnow + 1;
                        q.emplace(next);
                    }
                }
            }
        }
        return dis[n - 1][n - 2][0];
    }
};

