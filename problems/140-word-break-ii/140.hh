#include <vector>
#include <string>
#include <unordered_map>

struct node
{
    std::unordered_map<char, node*> child;
    bool end{};
};

struct Solution
{
    using res_type = std::vector<std::string>;

    node* root{new node};
    std::unordered_map<int, res_type> f;
    std::vector<std::string> res;

    void insert(std::string const& s)
    {
        auto p = root;
        for (auto ch : s) {
            if (!p->child.count(ch))
                p->child[ch] = new node;
            p = p->child[ch];
        }
        p->end = true;
    }

    void dfs(int d, int n, std::string const& s)
    {
        if (d == n || f.count(d))
            return;
        auto p = root;
        std::string next{};
        for (auto i = d; i < n; i++) {
            auto ch = s[i];
            if (!p->child.count(ch))
                return;
            p = p->child[ch];
            next += ch;
            if (p->end) {
                dfs(i + 1, n, s);
                for (auto const& str : f[i + 1]) {
                    if (str.empty())
                        f[d].emplace_back(next);
                    else
                        f[d].emplace_back(next + " " + str);
                }
            }
        }
    }

    res_type wordBreak(std::string s, std::vector<std::string>& wordDict)
    {
        for (auto const& s : wordDict)
            insert(s);
        f[s.size()] = {""};
        dfs(0, s.size(), s);
        return f[0];
    }
};

