# Reverse Linked List

标签： linked_list

---
## 题目描述
Reverse a singly linked list.

## 思路解析
### 迭代 
迭代时候，要注意保存节点的后继。
时间复杂度 $O(n)$， 空间复杂度 $O(1)$
### 递归
```
reverseList(head):
    p = reverseList(head->next)   // 逆序后续链表
    // 将p的后继指向head
    // head 的后继指向 null
```
时间复杂度 $T(n) = T(n-1) + O(1)$
得到 $T(n) = O(n)$
但是空间复杂度 O(n)

## 代码
### 迭代
```
class Solution 
{
public:
    ListNode* reverseList(ListNode* head) 
    {
        if(head == NULL)
            return head;
        ListNode* p = head;
        ListNode* r = p->next, *q = p;
        head-> next = NULL;
        while(r != NULL)
        {
            q = r;
            r = q->next;
            q->next = p;
            p = q;
        }
        return q;
    }
};
```
### 递归
```
class Solution 
{
public:
    ListNode* reverseList(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)
            return head;
        else
        {
            ListNode* q =head->next;
            ListNode* p = reverseList(q);
            q->next = head;
            head->next = NULL;
            return p;
        }
    }
};
```
