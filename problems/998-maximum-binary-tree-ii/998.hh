#pragma once

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

struct Solution
{
    auto insert(TreeNode* root, int val) -> TreeNode*
    {
        if (!root) {
            return new TreeNode(val);
        } else {
            if (val > root->val) {
                auto p = new TreeNode(val);
                p->left = root;
                return p;
            } else {
                root->right = insert(root->right, val);
                return root;
            }
        }
    }

    TreeNode* insertIntoMaxTree(TreeNode* root, int val)
    {
        return insert(root, val);
    }
};

