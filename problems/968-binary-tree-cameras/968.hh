#pragma once
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

auto constexpr inf = 1<<30;

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
    std::unordered_set<TreeNode*> all;
    int count{0};

    void dfs(TreeNode* u, TreeNode* parent)
    {
        if (!u) return;
        dfs(u->left, u);
        dfs(u->right, u);

        if (all.count(u) || all.count(u->left) || all.count(u->right))
            return;
        if (!parent) {
            all.emplace(u);
            count++;
            return;
        }
        if (!all.count(parent)) {
            all.emplace(parent);
            count++;
        }
    }

    int minCameraCover(TreeNode* root)
    {
        dfs(root, nullptr);
        return count;
    }
};

