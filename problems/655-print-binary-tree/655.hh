#pragma once
#include <vector>
#include <string>

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
    int h;
    int m;

    auto height(node_type u)
    {
        if (!u) return 0;
        return std::max(height(u->left), height(u->right)) + 1;
    }

    void draw(node_type u, std::vector<std::vector<std::string>>& board, int l, int r, int d = 0)
    {
        if (!u) return;
        auto mid = (l + r) / 2;
        board[d][mid] = std::to_string(u->val);
        draw(u->left,  board, l,       mid, d + 1);
        draw(u->right, board, mid + 1, r,   d + 1);
    }

    std::vector<std::vector<std::string>> printTree(TreeNode* root)
    {
        h = height(root);
        m = (1<<h) - 1;
        std::vector<std::vector<std::string>> res(h, std::vector<std::string>(m));
        draw(root, res, 0, m - 1);
        return res;
    }
};

