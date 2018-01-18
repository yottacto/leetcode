#pragma once

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

class Solution
{

    ListNode* next(ListNode* node) { return node->next; }

public:
    ListNode* detectCycle(ListNode* head)
    {
        if (!head) return nullptr;
        auto slower = head;
        auto faster = head;
        for (; faster->next && faster->next->next; ) {
            slower = next(slower);
            faster = next(next(faster));
            if (slower == faster) {
                for (; slower != head; ) {
                    slower = next(slower);
                    head = next(head);
                }
                return head;
            }
        }
        return nullptr;
    }
};

