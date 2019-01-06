#pragma once
#include <vector>
#include <unordered_map>
#include <set>

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
    std::vector<int> v;
    std::unordered_map<TreeNode*, int> size;
    std::vector<int> res;

    int dfs(TreeNode* root)
    {
        if (!root) return 0;
        return size[root] = dfs(root->left) + dfs(root->right) + 1;
    }

    bool check(TreeNode* root, int l, int r)
    {
        if (!root)
            return l == r;
        if (r - l != size[root])
            return false;
        if (root->val != v[l])
            return false;
        auto ll = l + 1;
        auto lr = l + 1 + size[root->left];
        if (lr > ll) {
            if (root->left->val != v[ll]) {
                res.emplace_back(root->val);
                std::swap(root->left, root->right);
                lr = l + 1 + size[root->left];
            }
        }
        if (!check(root->left, ll, lr))
            return false;
        if (!check(root->right, lr, r))
            return false;
        return true;
    }

    std::vector<int> flipMatchVoyage(TreeNode* root, std::vector<int>& voyage)
    {
        size[nullptr] = 0;
        dfs(root);

        v = voyage;
        if (check(root, 0, v.size()))
            return res;
        else
            return {-1};
    }
};

