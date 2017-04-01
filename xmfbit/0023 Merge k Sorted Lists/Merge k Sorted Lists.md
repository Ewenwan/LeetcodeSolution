# Merge k Sorted Lists

标签： heap

---
## 题目描述

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity. 

## 思路分析

一种朴素的方法是在N次迭代中（N是元素的总数），选取K个链表中的最小值，并将其取出，当前链表指针后移。

```
vector<TreeNode*> lists;
for i = 1:N
   int min_idx = 1
   for j = 2:K
       if lists[min_idx]->val > v[j]->val :
           min_idx = j
   // add lists[min_idx] to the end of sorted list
   lists[min_idx] = lists[min_idx]->next
```
这样做的时间复杂度为O(n*k)。在每次迭代中，要做K个内循环确定当前的最小值，我们可以使用一个最小堆来维护。每次的最小值直接可以由最小堆的根节点得到，并将其后继插入最小堆中并调整堆使其重新满足最小堆的性质。得到最小值的时间为常数，调整堆的时间为O(lg(n))。这样做整体的时间复杂度为O(nlg(k))。

## 代码

```
struct Comp {
public:
    bool operator()(const ListNode* lhs, const ListNode* rhs) const {
        return lhs->val > rhs->val;
    }    
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(0);   // 建立一个虚拟头节点
        // 可以使用STL中的优先队列作为最小堆的实现
        priority_queue<ListNode*, vector<ListNode*>, Comp> pd;
        for(auto node:lists) {
            if(node != nullptr) pd.push(node);
        }
        auto p = head;
        while(!pd.empty()) {
            auto top = pd.top();
            pd.pop();
            if(top->next != nullptr) pd.push(top->next);
            p->next = top;
            p = top;
        }
        p = head->next;
        delete head;
        return p;
    }
};
```

