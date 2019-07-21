#include <algorithm>

// // Definition for singly-linked list.
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

// TODO bottom-up merge sort

// recurrence and dive-and-conquer, O(logn) space
struct Solution
{
    auto sort(ListNode* first, int n) -> ListNode*
    {

        // std::cout << "n=" << n << ", [";
        // for (auto p = first; p; p = p->next)
        //     std::cout << p->val << " ";
        // std::cout << "]\n";

        if (n == 1) {
            first->next = nullptr;
            return first;
        }
        auto mid = first;
        auto lsize = n/2;
        auto rsize = n - lsize;
        for (auto i = 0; i < lsize; i++)
            mid = mid->next;
        auto l = sort(first, lsize);
        auto r = sort(mid, rsize);
        ListNode* head{};
        if (l->val <= r->val) {
            head = l;
            l = l->next;
        } else {
            head = r;
            r = r->next;
        }
        auto res = head;
        auto move = [&](auto& p) {
            head->next = p;
            head = p;
            p = p->next;
        };
        for (auto i = 1; i < n; i++) {
            if (l && r) {
                if (l->val <= r->val)
                    move(l);
                else
                    move(r);
            } else if (l) {
                move(l);
            } else {
                move(r);
            }
        }
        head->next = nullptr;
        return res;
    }

    ListNode* sortList(ListNode* head)
    {
        if (!head) return {};
        auto n = 0;
        for (auto p = head; p; p = p->next)
            n++;
        return sort(head, n);
    }
};

