/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#ifdef DEBUG
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#endif

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur1 = head;
        for (int i = 0; i < n; ++i) {
            cur1 = cur1->next;
        }
        ListNode* cur2 = head;
        ListNode* prev = nullptr;
        while (cur1) {
            cur1 = cur1->next;
            prev = cur2;
            cur2 = cur2->next;
        }
        if (prev) {
            prev->next = cur2->next;
        } else {
            head = head->next;
        }
        return head;
    }
};