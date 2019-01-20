#pragma once
#include <queue>
#include <unordered_map>

#define DEBUG 0

#if DEBUG
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
#endif

template <class T>
T abs(T x)
{
    return x < 0 ? -x : x;
}

struct Solution
{
    std::unordered_map<TreeNode*, TreeNode*> parent;
    std::unordered_map<TreeNode*, int> son;
    std::queue<TreeNode*> q;

    void dfs(TreeNode* u, TreeNode* p)
    {
        if (!u) return;
        parent[u] = p;
        son[u] = (u->left ? 1 : 0) + (u->right ? 1 : 0);
        if (!son[u])
            q.emplace(u);
        dfs(u->left, u);
        dfs(u->right, u);
    }

    int distributeCoins(TreeNode* root)
    {
        dfs(root, nullptr);
        auto ans = 0;
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            if (u == root) break;
            ans += abs(1 - u->val);
            parent[u]->val += u->val - 1;
            son[parent[u]]--;
            if (!son[parent[u]])
                q.emplace(parent[u]);
        }
        return ans;
    }
};

