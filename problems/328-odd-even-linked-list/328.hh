// // Definition for singly-linked list.
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

struct Solution
{
    ListNode* oddEvenList(ListNode* head)
    {
        if (!head)
            return {};
        auto p = head->next;
        auto even_head = p;
        auto op = head;
        auto ep = even_head;
        if (p)
            p = p->next;
        while (p) {
            op->next = p;
            op = p;
            p = p->next;
            ep->next = p;
            if (!p)
                break;
            ep = p;
            p = p->next;
        }
        op->next = even_head;
        return head;
    }
};

