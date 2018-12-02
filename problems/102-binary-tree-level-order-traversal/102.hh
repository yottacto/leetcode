#pragma once
#include <initializer_list>
#include <vector>

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
    using node_type = TreeNode*;

    void dfs(node_type u, std::vector<std::vector<int>>& res, int d = 0)
    {
        if (!u) return;
        if ((int)res.size() <= d)
            res.emplace_back(std::initializer_list<int>{u->val});
        else
            res[d].emplace_back(u->val);
        dfs(u->left, res, d + 1);
        dfs(u->right, res, d + 1);
    }

    auto levelOrder(TreeNode* root)
    {
        std::vector<std::vector<int>> res;
        dfs(root, res);
        return res;
    }
};

