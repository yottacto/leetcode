// // Definition for a Node.
// struct Node
// {
//     int val;
//     Node* next;
//     Node* random;
//     Node() {}
//     Node(int val, Node* next, Node* random)
//         : val(val), next(next), random(random) {}
// };

struct Solution
{
    Node* interweave(Node* p1, Node* p2)
    {
        auto head = p1;
        for (; p1; ) {
            auto tp1 = p1->next;
            p1->next = p2;
            auto tp2 = p2->next;
            p2->next = tp1;
            p1 = tp1;
            p2 = tp2;
        }
        return head;
    }

    Node* copyRandomList(Node* head)
    {
        if (!head)
            return {};
        auto new_head = new Node(head->val, nullptr, nullptr);
        auto np = new_head;
        for (auto p = head->next; p; p = p->next) {
            np->next = new Node(p->val, nullptr, nullptr);
            np = np->next;
        }
        auto phead = interweave(head, new_head);
        for (auto p = phead; p; ) {
            auto np = p->next;
            if (p->random)
                np->random = p->random->next;
            p = np->next;
        }
        auto res = phead->next;
        auto p1 = phead;
        auto p2 = phead->next;
        for (auto p = phead; p; ) {
            auto np = p->next;
            if (p1 != p) {
                p1->next = p;
                p1 = p;
                p2->next = np;
                p2 = np;
            }
            p = np->next;
            p1->next = nullptr;
            p2->next = nullptr;
        }
        return res;
    }
};

