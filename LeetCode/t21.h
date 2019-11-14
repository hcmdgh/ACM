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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode *head, *tail;
        head = tail = new ListNode(0);
        while (cur1 || cur2) {
            if (!cur2 || (cur1 && cur1->val < cur2->val)) {
                tail->next = new ListNode(cur1->val);
                tail = tail->next;
                cur1 = cur1->next;
            } else {
                tail->next = new ListNode(cur2->val);
                tail = tail->next;
                cur2 = cur2->next;
            }
        }
        return head->next;
    }
};