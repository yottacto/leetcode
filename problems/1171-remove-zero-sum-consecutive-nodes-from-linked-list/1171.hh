#include <algorithm>

// // Definition for singly-linked list.
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

struct Solution
{
    ListNode* hhead;

    bool remove()
    {
        auto sum = 0;
        std::unordered_map<int, ListNode*> psum;
        auto p = hhead;
        for (; p; p = p->next) {
            sum += p->val;
            if (psum.count(sum)) {
                psum[sum]->next = p->next;
                return true;
            } else {
                psum[sum] = p;
            }
        }
        return false;
    }

    ListNode* removeZeroSumSublists(ListNode* head)
    {
        hhead = new ListNode(0);
        hhead->next = head;
        while (remove())
            ;
        return hhead->next;
    }
};

