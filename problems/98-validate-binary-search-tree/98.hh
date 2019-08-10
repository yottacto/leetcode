#include <optional>

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
    bool check(int x, std::optional<int> l, std::optional<int> r)
    {
        return (!l || l.value() < x)
            && (!r || x < r.value());
    }

    bool valid_bst_helper(TreeNode* u, std::optional<int> lower, std::optional<int> upper)
    {
        if (!u)
            return true;
        auto v = u->val;
        if (!(check(v, lower, upper)))
            return false;
        return valid_bst_helper(u->left, lower, v)
            && valid_bst_helper(u->right, v, upper);

    }

    bool isValidBST(TreeNode* root)
    {
        return valid_bst_helper(root, {}, {});
    }
};

