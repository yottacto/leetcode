#pragma once
#include <string>
#include <unordered_map>

std::unordered_map<char, int> id{
     {'R', 0},
     {'Y', 1},
     {'B', 2},
     {'G', 3},
     {'W', 4},
};

struct Solution
{
    int step{10};

    bool remove(std::string& s)
    {
        int n = s.size();
        for (auto i = 0; i < n; i++) {
            auto j = i;
            while (j < n && s[j] == s[i])
                j++;
            if (j - i >= 3) {
                s.erase(i, j - i);
                return true;
            }
        }
        return false;
    }

    std::string insert(std::string s, char ch, int p)
    {
        s.insert(p + 1, 1, ch);
        while (remove(s));
        return s;
    }

    std::string remove(std::string s, int p)
    {
        s.erase(p, 1);
        return s;
    }

    void dfs(std::string board, std::string hand, int depth = 0)
    {
        // std::cout << "dfs: " << board << " - " << hand << " dep: " << depth << "\n";
        if (board.empty()) {
            step = std::min(step, depth);
            return;
        }
        if (hand.empty())
            return;
        int n = board.size();
        auto maxp = n == 1 ? 1 : n - 1;
        for (auto i = 0; i < maxp; i++) {
            bool vis[5] = {};
            for (auto j = 0u; j < hand.size(); j++) {
                auto c = hand[j];
                if (!vis[id[c]] && (c == board[i] || c == board[i+1])) {
                    vis[id[c]] = true;
                    dfs(insert(board, c, i), remove(hand, j), depth + 1);
                }
            }
        }
    }

    int findMinStep(std::string board, std::string hand)
    {
        dfs(board, hand, 0);
        return step >= 10 ? -1 : step;
    }
};

