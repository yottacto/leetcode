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
    int n;
    int x;
    int left{};
    int right{};

    int dfs(TreeNode* u)
    {
        if (!u)
            return 0;
        auto left = dfs(u->left);
        auto right = dfs(u->right);
        if (u->val == x) {
            this->left = left;
            this->right = right;
        }
        return left + right + 1;
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x)
    {
        this->n = n;
        this->x = x;
        dfs(root);
        auto max = std::max(n - left - right - 1, std::max(left, right));
        return max >= n - max;
    }
};

