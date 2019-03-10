#pragma once
#include <vector>
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
    template <class Iter>
    TreeNode* construct(Iter first, Iter last)
    {
        if (first == last)
            return nullptr;
        TreeNode* root = new TreeNode(*first);
        auto mid = std::find_if(first, last, [&](auto x) {
            return x > *first;
        });
        root->left = construct(std::next(first), mid);
        root->right = construct(mid, last);
        return root;
    }

    TreeNode* bstFromPreorder(std::vector<int>& preorder)
    {
        return construct(preorder.begin(), preorder.end());
    }
};

