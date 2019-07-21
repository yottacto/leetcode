#include <vector>
#include <unordered_map>
#include <string>

struct node
{
    std::unordered_map<char, node*> child;
    bool end{};
};

struct Solution
{
    node* root{new node};

    void insert(std::string const& word)
    {
        auto p = root;
        for (auto ch : word) {
            if (!p->child.count(ch))
                p->child[ch] = new node;
            p = p->child[ch];
        }
        p->end = true;
    }

    bool wordBreak(std::string s, std::vector<std::string>& wordDict)
    {
        for (auto const& word : wordDict)
            insert(word);
        int n = s.size();
        std::vector<int> f(n + 1);
        f[0] = true;
        for (auto i = n - 1; i >= 0; i--) {
            auto p = root;
            for (auto j = i; j < n; j++) {
                if (!p->child.count(s[j]))
                    break;
                p = p->child[s[j]];
                if (p->end)
                    f[n - i] |= f[n - j - 1];
            }
        }
        return f[n];
    }
};

