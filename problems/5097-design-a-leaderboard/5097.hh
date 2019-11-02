#include <map>
#include <unordered_map>

struct Leaderboard
{
    std::map<int, int> count;
    std::unordered_map<int, int> id;

    Leaderboard()
    {
    }

    void addScore(int playerId, int score)
    {
        if (id.count(playerId)) {
            auto now = id[playerId];
            count[now]--;
            if (!count[now])
                count.erase(now);
            now += score;
            count[now]++;
            id[playerId] = now;
        } else {
            id[playerId] = score;
            count[score]++;
        }
    }

    int top(int k)
    {
        auto it = count.rbegin();
        auto c = 0;
        auto sum = 0;
        for (; c < k && it != count.rend(); ++it) {
            if (c + it->second >= k) {
                sum += it->first * (k - c);
                c = k;
            } else {
                sum += it->first * it->second;
                c += it->second;
            }
        }
        return sum;
    }

    void reset(int playerId)
    {
        auto now = id[playerId];
        count[now]--;
        if (!count[now])
            count.erase(now);
        count[0]++;
        id[playerId] = 0;
    }
};

