# Rotate List

标签： two_pointer

---
## 题目描述
Given a list, rotate the list to the right by `k` places, where `k` is non-negative.

For example:
Given `1->2->3->4->5->NULL` and `k = 2`,
return `4->5->1->2->3->NULL`.

## 思路分析
需要找到移动位置的节点区间，直接将其移动至链表头即可。这项任务可以通过设置快慢指针，使两个指针的初始间距为`k`实现。

## 代码
```
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return head;
        int len = 0;
        ListNode* fast = head;
        // 得到链表长度
        while(fast != nullptr) {
            fast = fast->next;
            ++len;
        }
        k = k % len;   // 去除周期
        if(k == 0)  return head;
        ListNode* slow = head;
        fast = head;
        // 设置快指针
        for(int i = 0; i < k; ++i) fast = fast->next;
        while(fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }  // (slow, fast] 即为要移动的节点区间
        ListNode* new_head = slow->next;
        slow->next = fast->next;
        fast->next = head;
        return new_head;
    }
};
```




