// // Definition for singly-linked list.
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

struct Solution
{
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int carry = 0;
        if (!l1)
            l1 = new ListNode(0);
        auto p = l1;
        for (; p; ) {
            int s = carry;
            if (l2) {
                s += l2->val;
                l2 = l2->next;
            }
            s += p->val;
            carry = s / 10;
            if (!p->next && (l2 || carry))
                p->next = new ListNode(0);
            s %= 10;
            p->val = s;
            p = p->next;
        }
        return l1;
    }
};

