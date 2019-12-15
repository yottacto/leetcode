// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct Solution
{
    int getDecimalValue(ListNode* head)
    {
        auto sum = 0;
        for (; head; head = head->next)
            sum = sum * 2 + head->val;
        return sum;
    }
};

