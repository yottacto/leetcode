// // Definition for singly-linked list.
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

struct Solution
{
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        auto count = 0;
        auto target = head;
        for (auto p = head; p; p = p->next) {
            if (count < n + 1)
                count++;
            else
                target = target->next;
        }
        if (count < n + 1)
            return head->next;
        target->next = target->next->next;
        return head;
    }
};

