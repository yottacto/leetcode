#include <vector>
#include <algorithm>
#include <iterator>

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
    template <class Iter>
    TreeNode* build(Iter pre_first, Iter pre_last, Iter in_first, Iter in_last)
    {
        if (pre_first == pre_last)
            return nullptr;
        auto root = new TreeNode(*pre_first);
        auto it = std::find(in_first, in_last, *pre_first);
        auto left_size = std::distance(in_first, it);
        root->left = build(
            std::next(pre_first, 1), std::next(pre_first, 1 + left_size),
            in_first, it
        );
        root->right = build(
            std::next(pre_first, 1 + left_size), pre_last,
            std::next(it, 1), in_last
        );
        return root;
    }

    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder)
    {
        return build(
            preorder.begin(), preorder.end(),
            inorder.begin(), inorder.end()
        );
    }
};

