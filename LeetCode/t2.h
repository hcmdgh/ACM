#ifdef DEBUG
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#endif

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        int carry = 0;
        ListNode *res_head = nullptr, *res_tail = nullptr;
        while (l1 || l2 || carry) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            ListNode* new_node = new ListNode(sum % 10);
            if (res_tail) {
                res_tail->next = new_node;
                res_tail = new_node;
            } else {
                res_head = res_tail = new_node;
            }
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return res_head;
    }
};