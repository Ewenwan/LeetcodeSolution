# Insertion Sort List

标签： linked_list

---

## 题目描述
Sort a linked list using insertion sort.

## 思路分析
对于每个元素`Lj`，找到其正确位置，插入。循环不变式：保持`head`到指针`p`之间（左闭右开）的元素有序。
在头部加入哨兵元素`vir_node`，简化在头部的插入。
开始时，指针初始化为`head->next`，循环不变式成立。
如果该元素已经在了正确位置，指针后移，不变式成立。
如果该元素不在正确位置，则插入，后指针为原来的后继。不变式成立。
由于是单链表，所以记录节点的前驱，以便插入。

## 代码
```
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL)    return head;
        ListNode* vir_node = new ListNode(-INT_MAX);
        vir_node->next = head;
        ListNode* p = head->next;
        ListNode* p_parent = head;
        while(p != NULL) {
            ListNode* s = p->next;
            ListNode* q = vir_node;
            ListNode* r = q->next;
            while(r != p && r->val <= p->val) {
                q = r;
                r = r->next;
            }
            if(r != p) {
                // insert p after q
                q->next = p;
                p_parent->next = s;
                p->next = r;
            } else {
                p_parent = p; 
            }
            p = s;
        }
        ListNode* new_head = vir_node->next;
        delete vir_node;
        return new_head;
    }
};
```




