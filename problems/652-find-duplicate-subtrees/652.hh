#pragma once
#include <algorithm>
#include <functional>
#include <vector>

// // Definition for a binary tree node.
// struct TreeNode
// {
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     int val;
//     TreeNode *left;
//     TreeNode *right;
// };

auto equal_tree(TreeNode* u, TreeNode* v) -> bool
{
    if (!u && !v)
        return true;
    if (u && v) {
        if (u->val != v->val)
            return false;
        if (!equal_tree(u->left, v->left))
            return false;
        if (!equal_tree(u->right, v->right))
            return false;
        return true;
    } else {
        return false;
    }
}

// TODO better way without this comparison in O(n logn)?
auto less_tree(TreeNode* u, TreeNode* v) -> int
{
    if (!u && !v)
        return 0;
    if (u && v) {
        if (u->val != v->val)
            return u->val < v->val ? -1 : +1;
        auto left_cmp = less_tree(u->left, v->left);
        if (left_cmp)
            return left_cmp;
        return less_tree(u->right, v->right);
    } else {
        return (!u) ? -1 : +1;
    }
}

// nice c++ practice
template <class ForwardIt, class BinaryPredicate>
ForwardIt remove_unique(ForwardIt first, ForwardIt last, BinaryPredicate p)
{
    ForwardIt dest = first;
    while ((first = std::adjacent_find(first, last, p)) != last) {
        *dest = *first;
        ++first;
        ++dest;
        if ((first = std::adjacent_find(first, last, std::not2(p))) == last)
            break;
        ++first;
    }
    return dest;
}

struct Solution
{
    using vec_type = std::vector<TreeNode*>;

    void dfs(TreeNode* u, vec_type& nodes)
    {
        if (!u) return;
        nodes.emplace_back(u);
        dfs(u->left, nodes);
        dfs(u->right, nodes);
    }

    vec_type findDuplicateSubtrees(TreeNode* root)
    {
        vec_type nodes;
        dfs(root, nodes);
        std::sort(nodes.begin(), nodes.end(), [](TreeNode* lhs, TreeNode* rhs) {
            return less_tree(lhs, rhs) < 0;
        });
        nodes.erase(remove_unique(nodes.begin(), nodes.end(), std::ref(equal_tree)), nodes.end());
        return nodes;
    }
};

