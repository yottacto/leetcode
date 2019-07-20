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
    int countNodes(TreeNode* root)
    {
        if (!root)
            return 0;
        auto h = 0;
        for (auto p = root; p; p = p->left)
            h++;
        auto u = root;
        auto val = 1;
        for (auto hi = 1; hi < h; hi++) {
            auto th = hi;
            for (auto p = u->right; p; p = p->left)
                th++;
            if (th == h){
                u = u->right;
                val = (val << 1) ^ 1;
            } else {
                u = u->left;
                val <<= 1;
            }
        }
        return val;
    }
};

