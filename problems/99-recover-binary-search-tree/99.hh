#pragma once
#include <algorithm>

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

auto constexpr inf = 1<<30;

struct Solution
{
    TreeNode* pre;
    TreeNode* first;
    TreeNode* second;

    void traverse(TreeNode* u)
    {
        if (!u) return;
        traverse(u->left);
        if (!first && pre->val > u->val)
            first = pre;
        if (first && pre->val > u->val)
            second = u;
        pre = u;
        traverse(u->right);
    }

    void recoverTree(TreeNode* root)
    {
        TreeNode tmp(-inf);
        pre = &tmp;
        traverse(root);
        std::swap(first->val, second->val);
    }
};

