#include <utility>

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
    std::pair<bool, int> find(TreeNode* root, int& k)
    {
        if (!root) return {};
        if (auto res = find(root->left, k); res.first)
            return res;
        k--;
        if (!k)
            return {true, root->val};
        if (auto res = find(root->right, k); res.first)
            return res;
        return {};
    }

    int kthSmallest(TreeNode* root, int k)
    {
        return find(root, k).second;
    }
};

