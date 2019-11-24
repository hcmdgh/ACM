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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0)
            return head;
        int len = 0;
        ListNode *cur = head, *tail = nullptr;
        while (cur) {
            ++len;
            tail = cur;
            cur = cur->next;
        }
        tail->next = head;
        cur = head;
        for (int i = 0; i < len - k % len - 1; ++i) {
            cur = cur->next;
        }
        ListNode *new_head = cur->next;
        cur->next = nullptr;
        return new_head;
    }
};