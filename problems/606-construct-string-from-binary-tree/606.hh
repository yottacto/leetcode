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
    std::string dfs(TreeNode* t)
    {
        if (!t)
            return {};
        auto left = dfs(t->left);
        auto right = dfs(t->right);
        if (t->left || (!t->left && t->right))
            left = '(' + left + ')';
        if (t->right)
            right = '(' + right + ')';
        return std::to_string(t->val) + left + right;
    }

    std::string tree2str(TreeNode* t)
    {
        return dfs(t);
    }
};

