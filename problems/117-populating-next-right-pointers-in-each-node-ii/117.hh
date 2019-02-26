#pragma once
#include <vector>

// // Definition for a Node.
// struct Node
// {
//     int val;
//     Node* left;
//     Node* right;
//     Node* next;
//     Node() {}
//     Node(int _val, Node* _left, Node* _right, Node* _next)
//     {
//         val = _val;
//         left = _left;
//         right = _right;
//         next = _next;
//     }
// };

struct Solution
{

    Node* connect(Node* root)
    {
        auto now = root;
        Node* tail{nullptr};
        Node* head{nullptr};
        while (now) {
            if (now->left) {
                if (tail)
                    tail = tail->next = now->left;
                else
                    head = tail = now->left;
            }
            if (now->right) {
                if (tail)
                    tail = tail->next = now->right;
                else
                    head = tail = now->right;
            }
            if (!(now = now->next)) {
                now = head;
                head = tail = nullptr;
            }
        }
        return root;
    }
};

