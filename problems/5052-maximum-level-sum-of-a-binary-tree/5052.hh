#include <unordered_map>

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
    std::unordered_map<int, int> count;

    void dfs(TreeNode* root, int depth)
    {
        if (!root)
            return;
        count[depth] += root->val;
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }

    int maxLevelSum(TreeNode* root)
    {
        dfs(root, 1);
        auto res = -(1<<30);
        auto l = -1;
        for (auto const& p : count) {
            if (p.second > res) {
                res = p.second;
                l = p.first;
            }
        }
        return l;
    }
};

