#pragma once
#include <string>
#include <unordered_map>

struct node
{
    std::unordered_map<char, node*> child;
    bool end{};
};

struct WordDictionary
{
    node* root;

    // Initialize your data structure here.
    WordDictionary()
    {
        root = new node;
    }

    // Adds a word into the data structure.
    void addWord(std::string word)
    {
        auto p = root;
        for (auto ch : word) {
            if (!p->child.count(ch))
                p->child[ch] = new node;
            p = p->child[ch];
        }
        p->end = true;
    }

    auto dfs(std::string const& word, std::size_t pos, node* p)
    {
        if (pos == word.size())
            return p->end;
        if (word[pos] == '.') {
            for (auto const& c : p->child)
                if (dfs(word, pos + 1, c.second))
                    return true;
        } else {
            auto ch = word[pos];
            if (!p->child.count(ch))
                return false;
            if (dfs(word, pos + 1, p->child[ch]))
                return true;
        }
        return false;
    }

    // Returns if the word is in the data structure. A word could contain the
    // dot character '.' to represent any one letter.
    bool search(std::string word)
    {
        return dfs(word, 0, root);
    }
};

