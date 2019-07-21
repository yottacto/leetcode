#include <queue>

// // Definition for a Node.
// struct Node
// {
//     int val;
//     Node* left;
//     Node* right;
//     Node* next;
//     Node() {}
//     Node(int val, Node* left, Node* right, Node* next)
//         : val(val), left(left), right(right), next(next) {}
// };

struct Solution
{
    Node* connect(Node* root)
    {
        if (!root)
            return {};
        std::queue<Node*> q;
        q.emplace(root);
        while (!q.empty()) {
            int size = q.size();
            for (auto i = 0; i < size; i++) {
                auto u = q.front();
                q.pop();
                if (i < size - 1)
                    u->next = q.front();
                if (u->left) {
                    q.emplace(u->left);
                    q.emplace(u->right);
                }
            }
        }
        return root;
    }
};

