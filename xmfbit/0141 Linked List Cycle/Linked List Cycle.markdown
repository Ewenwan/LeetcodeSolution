# Linked List Cycle

标签：linked_list, two_pointer
---

## 题目描述
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space? 

## 思路分析
这个问题要求判断链表是否成环。一种思路就是用  链表 L记录访问过的节点，然后每访问一个新的节点，就去L里查询是否已经被访问过，如果已经被访问过，那么说明是有环的。但是显然这不是题目要求的解法。
这个问题是快慢指针的一个应用。我们 用两个指针，其中fast是slow移动 速度的两倍，那么可以想见，如果链表是成环的话，两个指针就会有相遇的时刻。如果没有环，那么fast指针会先到链表末尾。

下面对这个方案的正确性给出一个不是很严谨的说明，同时也能够看到初始条件的设定。

假设链表成环之前的节点个数是N1，环中节点的个数是N2（N1和N2都是大于等于0的。N2等于0说明不存在环），换之后节点的个数是N3。即链表中的节点总数为N=N1+N2+N3。
假设在T次迭代后，两个指针相遇在环的第x个节点（x>=0且x< N2）。那么我们有（m1，m2是在环内转的圈数）

N1+N2*m1+x=T*2（1式，对于快指针）

N1+N2*m2+x=T（2式，对于慢指针）

把2式代入1式，可以得到

(N1+x)/N2 = m1-2*m2

由于m1-2m2可以取遍所有正整数，也就是说(N1+x)必须能够整除N2.

这时候，如果令N1=0，可以发现x是不会 整除N2的，我们需要x+1。。。

所以，我们在循环追赶之前，应该让快指针领先慢指针一个身位，即`fast=slow->net`，这样1式就变成了

N1+N2*m1+x=T*2+1

之后可以得到(N1+x+1)必须能够整除N2。

- 当N1可以整除N2的时候，取x=0即可。

- 当N1< N2的时候，显然是可以的（取x=N2-N1-1）

- 当N1 > N2的时候，N1=N1-k*N2 化成N1小于N2的情景， 也是可以的。

所以，如果成环，那么必然两指针能够相遇。

而如果不成环，由于 fast初始比slow靠前，速度又快于slow，所以两者肯定不会相遇。

从而，解法是正确的。

## 代码
```
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr)
            return false;
        ListNode* slow = head, *fast = head->next;
        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            if(fast == slow)
                return true;
            slow = slow->next;
        }
        return false;
    }
};
```





