#include <string>

struct node
{
    node* child[26] = {};
    bool end{};
};

struct Trie
{
    node* root;

    // Initialize your data structure here.
    Trie()
    {
        root = new node;
    }

    // Inserts a word into the trie.
    void insert(std::string word)
    {
        auto p = root;
        for (auto ch : word) {
            if (!p->child[ch - 'a'])
                p->child[ch - 'a'] = new node;
            p = p->child[ch - 'a'];
        }
        p->end = true;
    }

    // Returns if the word is in the trie.
    bool search(std::string word)
    {
        auto p = root;
        for (auto ch : word) {
            if (!p->child[ch - 'a'])
                return false;
            p = p->child[ch - 'a'];
        }
        return p->end;
    }

    // Returns if there is any word in the trie that starts with the given
    // prefix.
    bool startsWith(std::string prefix)
    {
        auto p = root;
        for (auto ch : prefix) {
            if (!p->child[ch - 'a'])
                return false;
            p = p->child[ch - 'a'];
        }
        return true;
    }
};

