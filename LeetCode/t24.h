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
    ListNode* swapPairs(ListNode* head) {
        ListNode* cur = head;
        ListNode* new_head = new ListNode(0);
        ListNode* _prev = new_head;
        _prev->next = head;
        ListNode* _next;
        while (cur && (_next = cur->next)) {
            _prev->next = _next;
            cur->next = _next->next;
            _next->next = cur;
            _prev = cur;
            cur = cur->next;
        }
        return new_head->next;
    }
};