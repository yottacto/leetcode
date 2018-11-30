#pragma once
#include <unordered_map>
#include <algorithm>

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
    std::unordered_map<TreeNode*, int> depth;
    int deepest{};

    void get_depth(TreeNode* u, int d = 0)
    {
        if (!u) return;
        get_depth(u->left,  d + 1);
        get_depth(u->right, d + 1);
        depth[u] = std::max(d, std::max(depth[u->left], depth[u->right]));
    }

    TreeNode* all_deepest(TreeNode* u)
    {
        if (depth[u->left] == deepest && depth[u->right] == deepest)
            return u;
        if (depth[u->left] == deepest)
            return all_deepest(u->left);
        if (depth[u->right] == deepest)
            return all_deepest(u->right);
        return u;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root)
    {
        depth[nullptr] = 0;
        get_depth(root);
        deepest = depth[root];

        return all_deepest(root);
    }
};

