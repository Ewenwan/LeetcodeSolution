# Add Two Numbers II

标签： List

---

## 题目描述
nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:
```
Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
```

## 思路分析
如果不允许将链表reverse的话，很自然的思路是使用递归或栈。这里使用递归的思路来做。

记链表的长度分别为`l1`和`l2`，并假设它们之间满足`l1>=l2`。那么，根据`l1`和`l2`的大小，可以分成以下三种情况：
- 当`l1 == l2`时，可先计算后续链表的和，即`add(list1, list2, l1-1, l2-1)`，再接上；
- 当`l1 > l2`时，可先计算`add(list1, list2, l1-1, l2)`，再接上；
- 递归基，即`l1 == l2 == 1`，则直接计算。

## 代码
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int getLength(ListNode* l) {
        int sz = 0;
        while(l != NULL) {
            sz++;
            l = l->next;
        }
        return sz;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int& c, int sz1, int sz2) {
        if(sz1 == 1) {
            c = l1->val + l2->val;
            ListNode* node = new ListNode(c % 10);
            c = c/10;
            return node;
        }
        if(sz1 > sz2) {
            ListNode* prev_head = addTwoNumbers(l1->next, l2, c, sz1-1, sz2);
            c = l1->val + c;
            ListNode* node = new ListNode(c % 10);
            c = c/10;
            node->next = prev_head;
            return node;
        }
        ListNode* prev_head = addTwoNumbers(l1->next, l2->next, c, sz1-1, sz2-1);
        c = l1->val + l2->val + c;
        ListNode* node = new ListNode(c % 10);
        c = c / 10;
        node->next = prev_head;
        return node;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sz1 = getLength(l1);
        int sz2 = getLength(l2);
        ListNode* longer = l1, *shorter = l2;
        if(sz1 < sz2) {
            longer = l2;
            shorter = l1;
        }
        int c = 0;
        ListNode* node = addTwoNumbers(longer, shorter, c, max(sz1, sz2), min(sz1, sz2));
        if(c == 0) return node;
        ListNode* head = new ListNode(c);
        head->next = node;
        return head;
    }
};
```
