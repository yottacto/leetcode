#include <iostream>
#include "142.hh"

int main()
{
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);

    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l2;

    auto ans = Solution{}.detectCycle(&l1);
    if (ans)
        std::cout << ans->val << "\n";
    else
        std::cout << "null\n";
}

