# Swap Nodes in Pairs

标签： Linked_List

---

## 题目描述
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given `1->2->3->4`, you should return the list as `2->1->4->3`.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed. 

## 思路解析
递归大法好。
先解决头两个节点，然后再递归地解决后面的。
##代码
```
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* p = head, *q = p->next, *r = q->next;
        head = q;
        q -> next = p;
        p -> next = swapPairs(r);
        return head;
    }
};
```




