#pragma once

// // Definition for singly-linked list.
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

struct Solution
{
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if (!head) return head;
        ListNode* res{head};
        ListNode* last{nullptr};
        ListNode* bhead{head};
        for (auto count = 0; ; count++, head = head->next) {
            if (!count || (count % k)) {
                if (!head) break;
                continue;
            }
            ListNode* blast = bhead;
            ListNode* now = bhead->next;
            for (auto i = 1; i < k; i++) {
                ListNode* tmp = now->next;
                now->next = blast;
                blast = now;
                now = tmp;
            }
            if (count == k) res = blast;
            if (last) last->next = blast;
            last = bhead;
            bhead = now;
            if (!head) break;
        }
        if (last) last->next = bhead;
        return res;
    }
};

