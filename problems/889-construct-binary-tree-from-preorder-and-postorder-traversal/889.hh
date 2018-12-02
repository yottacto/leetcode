// NOTE: you may notice that knowing pre-order and post-order can't uniquely
// determine the tree, some subtree maybe either in left or right (when the
// sibling is empty), and the total number of possible trees is 2 to the number
// of these kind of uncertain subtrees's root.
#pragma once
#include <algorithm>
#include <iterator>
#include <vector>
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
    template <class Iterator>
    TreeNode* fill(Iterator first1, Iterator last1, Iterator first2, Iterator last2)
    {
        if (first1 == last1)
            return nullptr;
        auto root = new TreeNode(*first1);
        if (std::next(first1) == last1)
            return root;
        if (*std::next(first1) == *std::prev(last2, 2)) {
            root->left = fill(std::next(first1), last1, first2, std::prev(last2));
        } else {
            auto it1 = std::find(first1, last1, *std::prev(last2, 2));
            auto it2 = std::find(first2, last2, *std::next(first1));
            root->left  = fill(std::next(first1), it1,   first2,         std::next(it2));
            root->right = fill(it1,               last1, std::next(it2), std::prev(last2));
        }
        return root;
    }

    TreeNode* constructFromPrePost(
        std::vector<int> const& pre,
        std::vector<int> const& post
    )
    {
        return fill(pre.begin(), pre.end(), post.begin(), post.end());
    }
};

