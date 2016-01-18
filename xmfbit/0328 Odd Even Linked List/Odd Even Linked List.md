# Odd Even Linked List

标签： linked_list

---

##题目
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given `1->2->3->4->5->NULL`,
return `1->3->5->2->4->NULL`.

Note:
The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ... 

##思路分析
这道题的难度不大，首先思路是比较容易想到的。使用两个指针`odd`，`even`， 迭代向后移动，每次都把`even`的后继先给`odd`作为后继，然后`odd`后移，把它的后继再给`even`。最后，需要将两段链表合起来。也就是将`odd`的后继设为第一个偶数节点。在开始保存一下然后在最后赋值就可以了。

第一次提交失败，原因在迭代终止条件错误。（总结教训：在自己写例子的时候，太过着急，反而欲速不达）。 

## 代码
```
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)    return head;
        auto odd = head;
        auto even = odd->next;
        auto tmp = even;
        while(true) {
            odd->next = even->next;
            if(odd->next == nullptr) {   
                even->next = nullptr;
                break;
            }
            odd = odd->next;
            /*
             开始写成了 odd == odd->next;
             if(odd != nullptr) {
                ...
             }
            */
            even->next = odd->next;
            even = even->next;
            if(even == nullptr) break;
        }
        odd->next = tmp;
        return head;
    }
};
```



