#include <vector>
#include <string>

struct Solution
{
    std::vector<std::vector<int>> a;

    std::string player(int x)
    {
        if (x == 1)
            return "A";
        else
            return "B";
    }

    bool win(int x)
    {
        for (auto i = 0; i < 3; i++)
            if (a[i][0] == a[i][1] && a[i][0] == a[i][2] && a[i][0] == x)
                return true;
        for (auto i = 0; i < 3; i++)
            if (a[0][i] == a[1][i] && a[0][i] == a[2][i] && a[0][i] == x)
                return true;
        if (a[0][0] == a[1][1] && a[0][0] == a[2][2] && a[0][0] == x)
            return true;
        return (a[0][2] == a[1][1] && a[0][2] == a[2][0] && a[0][2] == x);
    }

    std::string tictactoe(std::vector<std::vector<int>>& moves)
    {
        a.resize(3, std::vector<int>(3));
        int n = moves.size();
        for (auto i = 0; i < n; i++) {
            auto move = moves[i];
            auto cur = (i&1) + 1;
            a[move[0]][move[1]] = cur;
            if (win(cur))
                return player(cur);
        }
        if (n == 9)
            return "Draw";
        return "Pending";
    }
};

