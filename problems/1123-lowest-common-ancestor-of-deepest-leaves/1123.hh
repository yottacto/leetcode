
// // Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

struct Solution
{
    int depth{};
    int count{};
    TreeNode* res{};

    void dfs(TreeNode* root, int d)
    {
        if (!root) return;
        if (d > depth) {
            depth = d;
            count = 1;
        } else if (d == depth) {
            count++;
        }
        dfs(root->left, d + 1);
        dfs(root->right, d + 1);
    }

    auto find(TreeNode* root, int d)
    {
        if (!root) return 0;
        auto count = (d == depth)
            + find(root->left, d + 1)
            + find(root->right, d + 1);
        if (count == this->count && !res) {
            res = root;
        }
        return count;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root)
    {
        dfs(root, 0);
        find(root, 0);
        return res;
    }
};

