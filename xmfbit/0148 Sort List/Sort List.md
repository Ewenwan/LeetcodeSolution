# Sort List

标签： sort, linked_list

---

## 题目描述
Sort a linked list in `O(n log n)` time using constant space complexity.

## 思路分析
要求使用`O(nlogn)`的时间复杂度，可以想到使用归并排序（快速排序在最坏时间复杂度不满足要求）。对链表进行归并排序，与数组相似，不过需要首先使用双指针获得链表的中点。这样，将链表划分为两半，再进行递归即可。

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
private:
    // get the middle position of the list
    ListNode* seekMid(ListNode* head) {
        if(head == NULL)    return NULL;
        ListNode* fast = head, *slow = head;
        while(fast->next != NULL) {
            fast = fast->next;
            if(fast->next == NULL)  break;
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
    // merge two list, just like merging array
    ListNode* mergeList(ListNode* r1, ListNode* r2) {
        ListNode* root = new ListNode(0), *p;
        p = root;
        while(r1 != NULL && r2 != NULL) {
            if(r1->val < r2->val) {
                p->next = r1;
                r1 = r1->next;
            } else {
                p->next = r2;
                r2 = r2->next;
            }
            p = p->next;
        }
        while(r1 != NULL) {
            p->next = r1;
            p = p->next;
            r1 = r1->next;
        }
        while(r2 != NULL) {
            p->next = r2;
            p = p->next;
            r2 = r2->next;
        }
        p->next = NULL;
        p = root->next;
        delete root;
        return p;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)  return head;
        ListNode* r1 = seekMid(head);
        ListNode* r2 = r1->next;
        r1->next = NULL;
        ListNode* h1 = sortList(head);
        ListNode* h2 = sortList(r2);
        return mergeList(h1, h2);
    }
};
```





