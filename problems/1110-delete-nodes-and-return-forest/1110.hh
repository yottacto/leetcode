#pragma once
#include <vector>
#include <unordered_set>

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
    template <class Vec>
    void dfs(TreeNode* u, TreeNode* parent, bool is_left, std::unordered_set<int> const& tod, Vec& res, bool is_root)
    {
        if (!u) return;
        if (tod.count(u->val)) {
            if (parent) {
                if (is_left)
                    parent->left = nullptr;
                else
                    parent->right = nullptr;
            }
            dfs(u->left, u, true, tod, res, true);
            dfs(u->right, u, false, tod, res, true);
        } else {
            if (is_root)
                res.emplace_back(u);
            dfs(u->left, u, true, tod, res, false);
            dfs(u->right, u, false, tod, res, false);
        }
    }

    std::vector<TreeNode*> delNodes(TreeNode* root, std::vector<int>& to_delete)
    {
        std::unordered_set<int> tod(to_delete.begin(), to_delete.end());
        std::vector<TreeNode*> res;

        dfs(root, nullptr, false, tod, res, true);

        return res;
    }
};

