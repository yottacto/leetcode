
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
    TreeNode* pruneTree(TreeNode* root)
    {
        if (!root)
            return {};
        auto left = pruneTree(root->left);
        root->left = left;
        auto right = pruneTree(root->right);
        root->right = right;
        auto has = root->val == 1 || right || left;
        return has ? root : nullptr;
    }
};

