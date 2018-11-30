#pragma once
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

auto constexpr inf = 1 << 30;

struct Solution
{
    using node_type = TreeNode*;

    std::unordered_map<node_type, int> path_sum;
    std::unordered_map<node_type, int> path_to_root_sum;

    void dfs(node_type u)
    {
        if (!u) return;
        dfs(u->left);
        dfs(u->right);
        path_to_root_sum[u] = std::max(
            u->val,
            std::max(
                path_to_root_sum[u->left]  + u->val,
                path_to_root_sum[u->right] + u->val
            )
        );
        path_sum[u] = std::max(
            std::max(
                path_sum[u->left],
                path_sum[u->right]
            ),
            std::max(0, path_to_root_sum[u->left]) +
            std::max(0, path_to_root_sum[u->right])
                + u->val
        );
    }

    int maxPathSum(TreeNode* root)
    {
        path_to_root_sum[nullptr] = 0;
        path_sum        [nullptr] = -inf;
        dfs(root);
        return path_sum[root];
    }
};

