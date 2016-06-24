# Remove Duplicates from Sorted List II

标签： linked_list

---
## 题目描述
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given `1->2->3->3->4->4->5`, return `1->2->5`.
Given `1->1->1->2->3`, return `2->3`. 

## 思路分析
这种链表题目适合在纸上写一下，关键就是指针的使用，因为是单链表，所以要了解如何保存节点的前驱，来达到删除节点的目的。

和其他类似题目的解法一样，我们可以先设置一个虚拟头节点，最后返回它的后继即可。

使用`p`标记当前节点的前驱，`q`标记当前节点，`r`用来遍历当前节点后面的节点，来确定第一个非重复节点的位置。

## 代码
```
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* vir = new ListNode(0);
        vir->next = head;
        ListNode* p = vir, *q = p->next;
        while(q != nullptr) {
            int key = q->val;
            ListNode* r = q->next;
            if(r == nullptr)    break;
            if(r->val == key) {
                while(r != nullptr && r->val == key) {
                    r = r->next;
                }
                p->next = r;
                q = r;
            } else {
                p = q;
                q = r;
            }
        }
        return vir->next;
    }
};
```




