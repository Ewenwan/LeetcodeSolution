# Reorder List

标签： linked_list

---
## 题目描述
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given `{1,2,3,4}`, reorder it to `{1,4,2,3}`. 
## 思路分析
使用递归来做，思路还是比较明确的。
```
reorderList(p, q):
  if(p == q || p->next == q)  // 如果只有单个节点或者两个节点
      return (p, q)           // 直接返回首尾节点组成的tuple 
  r = p->next 
  s = q->prev                // 获取当前首节点的后继，尾节点的前驱
  head, tail = reorderList(r, s)
  p->next = q
  tail->next = q->next
  q->next = tail
  return p, tail 
```
问题的关键在于如何求取`q`节点的前驱（因为是单链表）。可以每次都从首节点开始遍历，直到某节点的后继为`q`，则此节点为所求。这也是刚开始我的提交，结果果然TLE。毕竟每次都要使用cn的时间来检测。

后来，我使用了一个`stack`来储存节点（由递归的特点得到使用stack）。这样，用`stack`配合递归，就可以每次都得到相应的前驱了。

不过这样的话，不是就地逆序了，还没有满足题目的要求，需要在评论区学习一个~

## 代码
```
class Solution {
    stack<ListNode*> nodes;
    pair<ListNode*, ListNode*> recursive(ListNode* p, ListNode* q) {
        if(p == q || p->next == q) return {p, q};
        ListNode* s = nodes.top();
        nodes.pop();
        auto tuple = recursive(p->next, s);
        p->next = q;
        tuple.second->next = q->next;
        q->next = tuple.first;
        return {p, tuple.second};
    }
public:
    void reorderList(ListNode* head) {
        if(head == nullptr) return;
        ListNode* p = head;
        while(p->next != nullptr) {
            nodes.push(p);
            p = p->next;
        }
        recursive(head, p);
    }
};
```