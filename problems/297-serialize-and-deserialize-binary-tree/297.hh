#pragma once
#include <string>

// // Definition for a binary tree node.
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

struct Codec
{
    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root)
    {
        if (!root) return "nullptr";
        return std::to_string(root->val)
            + "," + serialize(root->left)
            + "," + serialize(root->right);
    }


    TreeNode* deserialize_impl(std::string& data)
    {
        std::string token;
        auto p = data.find_first_of(',');
        if (p == std::string::npos) {
            token = data;
        } else {
            token = data.substr(0, p);
            data.erase(0, p+1);
        }
        if (token == "nullptr")
            return nullptr;
        auto root = new TreeNode(std::stoi(token));
        root->left = deserialize_impl(data);
        root->right = deserialize_impl(data);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data)
    {
        return deserialize_impl(data);
    }
};

