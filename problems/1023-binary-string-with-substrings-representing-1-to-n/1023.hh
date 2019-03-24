#pragma once
#include <string>
#include <queue>

struct node
{
    node()
    {
        child[0] = child[1] = nullptr;
    }

    node* child[2];
};

struct Solution
{
    int l;
    node* root;

    void add(std::string s)
    {
        // std::cerr << "adding " << s << "\n";
        auto p = root;
        for (auto ch : s) {
            auto c = ch - '0';
            if (!p->child[c])
                p->child[c] = new node;
            p = p->child[c];
        }
    }

    auto calc() -> int
    {
        if (!root->child[1])
            return 0;
        std::queue<node*> q;
        auto count = 0;
        q.emplace(root->child[1]);
        count++;
        while (!q.empty()) {
            auto now = q.front();
            q.pop();
            if (!now->child[0])
                return count;
            q.emplace(now->child[0]);
            count++;
            if (!now->child[1])
                return count;
            q.emplace(now->child[1]);
            count++;
        }
        return count;
    }

    bool queryString(std::string s, int n)
    {
        root = new node;
        l = s.size();
        for (auto i = 0; i < l; i++)
            add(s.substr(i));
        // std::cout << calc() << "\n";
        return calc() >= n;
    }
};

