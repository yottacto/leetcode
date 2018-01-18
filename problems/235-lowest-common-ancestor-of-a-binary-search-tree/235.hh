#pragma once

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
    bool contain(TreeNode* root, TreeNode* p)
    {
        if (root == nullptr) return false;
        if (root == p) return true;
        return contain(root->left, p) || contain(root->right, p);
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == p || root == q) return root;
        auto p_in_left = contain(root->left, p);
        auto q_in_left = contain(root->left, q);

        if (p_in_left == q_in_left) {
            return p_in_left
                ? lowestCommonAncestor(root->left, p, q)
                : lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};

