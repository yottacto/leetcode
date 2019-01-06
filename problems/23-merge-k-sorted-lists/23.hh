#pragma once
#include <vector>
#include <queue>

// // Definition for singly-linked list.
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

struct Solution
{
    ListNode* mergeKLists(std::vector<ListNode*> const& lists)
    {
        ListNode* res{nullptr};
        ListNode* head{nullptr};
        auto cmp = [](auto const& a, auto const& b) {
            return a->val > b->val;
        };
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> pq{cmp};
        for (auto const& p : lists)
            if (p) pq.emplace(p);
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            if (!res) {
                res = new ListNode(top->val);
                head = res;
            } else {
                res->next = new ListNode(top->val);
                res = res->next;
            }
            if (top->next)
                pq.emplace(top->next);
        }
        return head;
    }
};

