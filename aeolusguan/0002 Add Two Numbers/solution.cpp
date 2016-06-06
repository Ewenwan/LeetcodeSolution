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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);
        ListNode* cur = result;
        int carry = 0;
        int digit = 0;
        while (l1 || l2) {
            if (!l1) {
                digit = l2->val + carry;
                l2 = l2->next;
            }
            else if (!l2) {
                digit = l1->val + carry;
                l1 = l1->next;
            }
            else {
                digit = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            }
            carry = 0;
            if (digit >= 10) {
                digit -= 10;
                carry = 1;
            }
            cur->next = new ListNode(digit);
            cur = cur->next;
        }
        if (carry) {
            cur->next = new ListNode(1);
        }
        return result->next;
    }
};
