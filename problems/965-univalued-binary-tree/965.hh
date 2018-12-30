#pragma once

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool isUnivalTree(TreeNode* root, int val = -1)
    {
        if (!root) return true;
        if (val != -1 && root->val != val)
            return false;
        auto v = root->val;
        return isUnivalTree(root->left, v)
            && isUnivalTree(root->right, v);
    }
};

