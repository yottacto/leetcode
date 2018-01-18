#include <iostream>
#include "235.hh"

int main()
{
    TreeNode n1{1};
    TreeNode n2{2};
    TreeNode n3{3};
    TreeNode n4{4};
    TreeNode n5{5};
    TreeNode n6{6};
    TreeNode n7{7};
    TreeNode n8{8};
    TreeNode n9{9};

    n6.left = &n2;
    n6.right = &n8;

    n2.left = &n1;
    n2.right = &n4;

    n4.left = &n3;
    n4.right = &n5;

    n8.left = &n7;
    n8.right = &n9;

    {
        auto ans = Solution{}.lowestCommonAncestor(&n6, &n2, &n8);
        std::cout << ans->val << "\n";
    }

    {
        auto ans = Solution{}.lowestCommonAncestor(&n6, &n2, &n4);
        std::cout << ans->val << "\n";
    }
}

