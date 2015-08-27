# Palindrome Linked List

标签： Linked_List two_pointer 

---
## 题目描述
Given a singly linked list, determine if it is a palindrome.

Could you do it in O(n) time and O(1) space?

## 思路解析

刚开始想到的思路是直接用递归。

```
isPolindrome(head, tail) = isPolindrome(head->next, tail->pre)
```
但是这样的问题是每次需要找到tail的前驱，可以得到

$$T(n) = T(n-2) + O(n)$$

推知： $$T(n) = O(n^2)$$

试着写了代码，TLE

接下来看了别人的答案，知道了怎么解决单向链表前驱每次都要O(n)复杂度确定的问题。**将链表分为两半，后一半逆序就可以了！**

所以，问题转换为了怎么确定链表的中心和如何逆序，前者可以通过双指针来解决，后者则是在每次迭代中，需要确定当前节点的前驱和后继，然后修改next指针，并更新，把关系理顺就好。

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
class Solution 
{
public:
    bool isPalindrome(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)
            return true;
        // find the middle node of the list
        ListNode* fast = head->next, *slow = head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        // reverse [slow+1,...fast]
        ListNode* p = slow;
        ListNode* q = slow->next;
        p->next = NULL;
        ListNode* r = q->next;
        while(r)
        {
            q->next = p;
            p = q;
            q = r;
            r = r->next;
        }
        q->next = p;
        for(p = head; p!=q && q->next != p; p = p->next, q = q->next)
            if(p->val != q->val)
                return false;
        return p->val == q->val;
    }
};
```

把我的TLE递归代码也贴上来吧。
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
private:
    bool isPalindrome(ListNode* head, ListNode* tail)
    {
        if(head == tail)
            return true;
        if(head->next == tail)
            return head->val == tail->val;
        ListNode* p = head;
        for(; p->next != tail; p = p->next);
        return head->val == tail->val && isPalindrome(head->next, p);
    }
public:
    bool isPalindrome(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)
            return true;
        ListNode* p = head;
        for(; p->next != NULL; p = p->next);
        return isPalindrome(head, p);
    }
};
```


