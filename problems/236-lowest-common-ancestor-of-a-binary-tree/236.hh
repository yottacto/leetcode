#include <stack>

// // Definition for a binary tree node.
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

enum class state
{
    left,
    right,
    back,
};

struct Solution
{
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        std::stack<std::pair<TreeNode*, state>> st;
        st.emplace(root, state::left);
        TreeNode* lca = nullptr;
        TreeNode* one_found = nullptr;
        while (!st.empty()) {
            auto [cur_p, cur_state] = st.top();
            if (cur_p == p || cur_p == q) {
                if (!one_found) {
                    one_found = cur_p;
                    lca = cur_p;
                } else if (cur_p != one_found) {
                    return lca;
                }
            }
            if (cur_state == state::left) {
                st.top().second = state::right;
                if (cur_p->left)
                    st.emplace(cur_p->left, state::left);
            } else if (cur_state == state::right) {
                st.top().second = state::back;
                if (cur_p->right)
                    st.emplace(cur_p->right, state::left);
            } else {
                st.pop();
                if (lca == cur_p)
                    lca = st.top().first;
            }
        }
        return nullptr;
    }
};

