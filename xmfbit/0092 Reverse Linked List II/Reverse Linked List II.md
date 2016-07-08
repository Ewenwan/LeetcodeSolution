# Reverse Linked List II

标签： linked_list

---

## 题目描述
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given `1->2->3->4->5->NULL`, `m = 2` and `n = 4`,

return `1->4->3->2->5->NULL`.

Note:
Given `m`, `n` satisfy the following condition:
`1 ≤ m ≤ n ≤ length of list`. 
## 思路分析
可以使用两个指针确定要reverse的链表段，然后reverse这一段，再将对应指针指过去就好了~

在下面的代码中，使用`reverse(p, q)`将`[p, q]`范围内的链表段逆序，并返回链表尾元素，在此过程中，维持`q`节点后的链表指向关系不变，所以在将这段链表逆序之后，只需再重新调整头节点即可。

## 代码
```
class Solution {
    // 使用递归的方法逆序[p, q]
    ListNode* reverse(ListNode* p, ListNode* q) {
        if(p == q) return p;
        ListNode* tail = reverse(p->next, q);
        ListNode* tmp = tail->next;  // 保持链表段后续节点不丢失
        tail->next = p;
        p->next = tmp;
        return p;
    }
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* guard = new ListNode(0);
        guard->next = head;
        ListNode* prev = guard;
        int i = 1;
        for(i = 1; i < m; ++i) {
            prev = prev->next;
        }
        ListNode* q = prev->next;
        for(i = m; i < n; ++i) {
            q = q->next;
        }
        reverse(prev->next, q);
        prev->next = q;
        ListNode* new_head = guard->next;
        delete guard;
        return new_head;
    }
};
```



