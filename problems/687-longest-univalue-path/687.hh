#include <algorithm>
#include <unordered_map>

// // Definition for a binary tree node.
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

struct Solution
{
    std::unordered_map<TreeNode*, int> f;
    int res{};

    void dfs(TreeNode* u)
    {
        if (!u)
            return;
        dfs(u->left);
        dfs(u->right);
        f[u] = 1;
        if (u->left && u->left->val == u->val)
            f[u] = std::max(f[u], f[u->left] + 1);
        if (u->right && u->right->val == u->val)
            f[u] = std::max(f[u], f[u->right] + 1);
        if (u->left && u->right && u->left->val == u->val
                && u->right->val == u->val)
            res = std::max(res, f[u->left] + f[u->right] + 1);
        res = std::max(res, f[u]);
    }

    int longestUnivaluePath(TreeNode* root)
    {
        if (!root)
            return 0;
        dfs(root);
        return res - 1;
    }
};

