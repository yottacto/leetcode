#include <string>
#include <vector>
#include <unordered_set>

struct node
{
    node* child[26] = {};
    int ith{};
};


struct Solution
{
    Solution() : root(new node) {}

    node* root;
    std::unordered_set<int> all;
    std::vector<std::vector<int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    std::vector<std::vector<char>> vis;

    void insert(std::string const& word, node* root, int ith)
    {
        auto p = root;
        for (auto ch : word) {
            if (!p->child[ch - 'a'])
                p->child[ch - 'a'] = new node;
            p = p->child[ch - 'a'];
        }
        p->ith = ith;
    }

    auto inrange(int x, int r)
    {
        return 0 <= x && x < r;
    }

    template <class T>
    void dfs(int i, int j, node* p, T const& board)
    {
        auto k = board[i][j] - 'a';
        if (!p->child[k])
            return;
        p = p->child[k];
        if (p->ith)
            all.emplace(p->ith - 1);
        vis[i][j] = true;
        for (auto const& d : dir) {
            auto ni = i + d[0];
            auto nj = j + d[1];
            if (inrange(ni, board.size()) && inrange(nj, board[0].size())
                    && !vis[ni][nj])
                dfs(ni, nj, p, board);
        }
        vis[i][j] = false;
    }

    std::vector<std::string> findWords(
        std::vector<std::vector<char>>& board,
        std::vector<std::string>& words
    )
    {
        int n = words.size();
        for (auto i = 0; i < n; i++)
            insert(words[i], root, i + 1);
        vis.resize(board.size(), std::vector<char>(board[0].size()));
        std::vector<std::string> res;
        for (auto i = 0u; i < board.size(); i++)
            for (auto j = 0u; j < board[0].size(); j++)
                dfs(i, j, root, board);
        for (auto i : all)
            res.emplace_back(words[i]);
        return res;
    }
};

