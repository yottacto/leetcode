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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == p || root == q) return root;
        auto p_in_left = p->val <= root->val;
        auto q_in_left = q->val <= root->val;

        if (p_in_left == q_in_left) {
            return p_in_left
                ? lowestCommonAncestor(root->left, p, q)
                : lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};

