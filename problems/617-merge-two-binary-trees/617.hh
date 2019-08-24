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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
    {
        if (!t1 && !t2)
            return {};
        if (!t1)
            std::swap(t1, t2);
        if (t2)
            t1->val += t2->val;
        t1->left = mergeTrees(t1 ? t1->left : nullptr, t2 ? t2->left : nullptr);
        t1->right = mergeTrees(t1 ? t1->right : nullptr, t2 ? t2->right : nullptr);
        return t1;
    }
};

