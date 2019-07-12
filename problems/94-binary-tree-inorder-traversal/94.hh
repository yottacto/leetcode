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

struct Solution
{
    std::vector<int> inorderTraversal(TreeNode* root)
    {
        std::vector<int> res;
        std::stack<TreeNode*> st;
        auto p = root;
        while (p || !st.empty()) {
            if (p) {
                st.emplace(p);
                p = p->left;
            } else {
                p = st.top();
                res.emplace_back(p->val);
                st.pop();
                p = p->right;
            }
        }
        return res;
    }
};

