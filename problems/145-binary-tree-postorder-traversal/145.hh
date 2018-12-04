#pragma once
#include <vector>
#include <stack>

// // Definition for a binary tree node.
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

struct data
{
    data(TreeNode* node) : node(node), has_value(false) {}
    data(int val) : val(val), has_value(true) {}

    auto is_node() const { return !has_value; }

    TreeNode* node{nullptr};
    int val;
    bool has_value;

};

struct Solution
{
    std::vector<int> postorderTraversal(TreeNode* root)
    {
        std::stack<data> stk;
        std::vector<int> res;
        stk.emplace(root);
        while (!stk.empty()) {
            auto top = stk.top();
            stk.pop();
            if (top.is_node()) {
                auto node = top.node;
                if (!node) continue;
                stk.emplace(node->val);
                stk.emplace(node->right);
                stk.emplace(node->left);
            } else {
                res.emplace_back(top.val);
            }
        }
        return res;
    }
};

