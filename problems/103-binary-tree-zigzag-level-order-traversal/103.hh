#include <vector>

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

    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        if (!root) return {};
        std::vector<std::vector<int>> res;
        std::vector<TreeNode*> rec[2];
        std::vector<int> tmp;
        auto now = 0;
        auto next = 1;
        auto dir = 1;
        res.emplace_back(std::vector<int>{root->val});
        rec[now].emplace_back(root);
        auto insert = [&](auto u) {
            if (u) {
                rec[next].emplace_back(u);
                tmp.emplace_back(u->val);
            }
        };
        for (; rec[now].size(); ) {
            rec[next].clear();
            tmp.clear();
            int n = rec[now].size();
            for (auto i = n - 1; i >= 0; i--) {
                auto u = rec[now][i];
                if (dir == 1) {
                    insert(u->right);
                    insert(u->left);
                } else {
                    insert(u->left);
                    insert(u->right);
                }
            }
            if (!tmp.empty())
                res.emplace_back(tmp);
            std::swap(now, next);
            dir ^= 1;
        }
        return res;
    }
};

