# Partition List

标签： link_list

---
## 题目描述
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given `1->4->3->2->5->2` and `x = 3`,
return `1->2->2->4->3->5`. 
## 思路分析
很容易想到快速排序里面的partition方法。
```
// a[0, ... ,r] partition
x = a[r]      // 选取最后一个元素作为枢纽
// 循环不变式：a[0,...i]始终小于等于x，a[i+1,...j-1]始终大于x，a[j,...,r-1]待处理
int i = -1, j = 0
while j < r  // 遍历a[0,...r-1]
   if a[j] <= x
      swap(a[j], a[++i])
swap(a[++i], a[r])
return i
```

然而，如果我们照搬快排里面的这个方法，会发现由于交换，破坏了稳定性。所以转而利用链表的性质来做插入就好了。

当采样插入而非交换的方法时候，由于排在后面的数据节点必然被插入到较后面的位置，所以保证了稳定性。
同时，按照题目要求，条件表达式改为小于号。
```
if j 节点的值 < x
    把 j节点插入到i节点之后
```
为了插入能够进行，我们必须要能够维护j节点的前驱，这样才能够将j的后继改为其前驱的后继，不至于丢掉j的后继。

## 代码
```
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* head_virtual = new ListNode(0); // 加一个虚拟头节点，方便处理
        head_virtual->next = head;
        ListNode* i = head_virtual, *j_prev = head_virtual, *j;
        while((j = j_prev->next) != nullptr) {
            if(j->val < x) {
                if(j == i->next)  {   // 如果j刚好是i的后继，则没有必要插入
                    i = i->next;     // 只要调整i并继续后移j_prev即可
                    j_prev = j_prev->next;
                }
                else {  // 需要将j插入到i后面
                    ListNode* p = i->next; 
                    j_prev->next = j->next; 
                    i->next = j;
                    j->next = p;   // 插入完成
                    i = j;   // 更新i为其后继
                }
            } else {   // 不需要插入，后移j_prev
                j_prev = j_prev->next;
            }
        }
        i = head_virtual->next;
        delete head_virtual;
        return i;
    }
};
```



