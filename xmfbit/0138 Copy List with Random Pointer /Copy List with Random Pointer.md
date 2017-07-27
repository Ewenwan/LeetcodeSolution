# Copy List with Random Pointer

标签：linked_list

---

## 题目描述
A linked list is given such that each node contains an additional random pointer
which could point to any node in the list or null.

Return a deep copy of the list.

```
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
```

## 思路
### 思路1（Naive）
最简单的一种思路（也是我想出的解决办法），是建立copy前后对应节点的对应关系。我想到了将链表1中
的节点和链表2中节点的地址分别作为`key`和`value`，使用`map`来存储，也即是这样：
```
map<RandomListNode*, RandomListNode*> the_mapping;
```

这样，我们就可以遍历链表1，查询链表2中对应的节点是否已经存在。如果不存在，则构造节点。否则，直接指向
该节点即可。并使用同样的办法找到其对应的`random`指针。

这种方法思路较为简单，但是对于每个节点，需要在`map`中进行查找两次，所以时间复杂度为`O(nlgn)`，
同时在`map`的实现中，要维护一个红黑树，空间复杂度为`O(n)`。

### 思路2（巧妙构造有序）
通过上面的分析，其实可以发现，这个问题难就难在了`random`指针的处理。否则，这就是一道很简单的链表题目。
`random`指针之所以是难点，是因为我们在建立节点的时候，没法知道其`random`节点是否建立了；那能不能
先整个建立链表，再逐一为每个节点的`random`指针赋值呢？也是不行的。因为我们不知道这个链表2中新建立的
`random`节点究竟在哪里。

有一种思路很巧妙，在建立链表2的时候，我将新建立的节点插入到链表1中对应节点的后面。这样，相当于为我们标记
了`random`节点的位置。因为我们有`n1->next => n2`这个关系。所以要找的那个`random`节点就是`n1->random->next`。
之后，我们再把链表L2抠出来就好了。

这种方法思路也很简单，很巧妙。我们只需要遍历链表3遍（插入链表2的各节点；修正其`random`指针；将链表1复原同时
分离链表2），所以时间复杂度是`O(n)`，同时空间复杂度为`O(1)`。

实际编程时要注意`nullptr`的处理。

### 思路3（`next`指针与`random`指针来回倒）
思路3较为绕圈，不过和思路2一样，这种方法也是尽量为链表1和链表2中的节点建立联系。只要掌握了其中体现出的关系式，
就能轻松理清。

思路3中，我们在建立链表2中的节点时，将其`next`指针指向对应链表1节点的`random`，同时将链表1中相应节点
的`random`指向链表2中的这个对应节点。

和思路2中的关系式`n1->next => n2`相比，这里的关系式实际上就是`n1->random => n2`，同时，`n1->random => n2->next`。这两个式子
左边都是操作前，右边对应操作后。

这样，我们先将链表2中的各个节点都建好。下一步，就是修正其`random`指针了。只需要根据此式子来赋值即可：`n2->random <= n2->next->random`。

最后，同样要对链表1进行复原，同时分离链表2.我们需要修正链表2节点的`next`指针和链表1节点的`random`指针。根据下面来更新：
```
n2->next <= n1->next->random
n1->random <= n2->next
```

我们没必要同时拿到`n1`和`n2`，因为`n1->random`就是`n2`。而且，我们需要在更新之前备份`n2->next`。所以，代码中实际采用了下面的更新方法：
```
tmp <= n2->next
n1->random->next <= n1->next->random
n1->random <= tmp
```

这种方法本质上和思路2没有太大区别，都是想办法做出链表1和2节点的对应关系，但是捋起来还是有点麻烦的。

## 代码
### 代码1（Naive）
```
class Solution {
private:
    typedef map<RandomListNode*, RandomListNode*> PointerMap;
    RandomListNode* transformPointer(RandomListNode* p,
                                     PointerMap& m) {
        auto iter = m.find(p);
        if(iter == m.end()) {
            auto q = new RandomListNode(p->label);
            m[p] = q;
            return q;
        } else {
            return iter->second;
        }
    }

public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        auto fake_head = new RandomListNode(0);
        PointerMap m;
        // 遍历原始的链表，做拷贝
        auto q = fake_head;
        for(auto p = head; p != nullptr; p = p->next) {
            auto n = transformPointer(p, m);
            q->next = n;
            q = n;
            auto random = p->random;
            if(random == nullptr) {
                n->random = nullptr;
            } else {
                n->random = transformPointer(random, m);
            }
        }
        q->next = nullptr;
        return fake_head->next;
    }
};
```

### 思路2（借助链表1标记`random`的位置）
```
class Solution {                        
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == nullptr) return nullptr;
        // 将L2的各个节点插入到L1对应节点后面
        auto p = head;
        while(p != nullptr) {
            auto n = new RandomListNode(p->label);
            n->next = p->next;
            p->next = n;
            p = n->next;
        }
        // random指针
        p = head;
        while(p != nullptr) {
            auto random = p->random;
            p->next->random = random == nullptr? nullptr: random->next;
            p = p->next->next;
        }
        // 抽出L2
        p = head;
        auto new_head = p->next;
        while(p != nullptr) {
            auto q = p->next;
            p->next = q->next;
            auto next = p->next;
            q->next = next == nullptr? nullptr: next->next;
            p = p->next;
        }
        return new_head;
    }
};
```

### 思路3（`next`和`random`互相利用）
```
class Solution {                        
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == nullptr) return nullptr;
        // 建立L2，其中节点的next是对应L1节点的random，同时让L1节点的random指向该节点
        for(auto p = head; p != nullptr; p = p->next) {
            auto n = new RandomListNode(p->label);
            n->next = p->random;
            p->random = n;
        }
        // 这样，我们使用n->random就可以得到L1中节点在L2中的对应节点了
        // 我们修正L2节点的random指针
        for(auto p = head; p != nullptr; p = p->next) {
            auto q = p->random->next;
            p->random->random = q == nullptr? nullptr: q->random;
        }
        // 将L2择出来
        auto new_head = head->random;
        for(auto p = head; p != nullptr; p = p->next) {
            auto q = p->next;
            auto n = p->random->next;
            p->random->next = q == nullptr? nullptr : q->random;
            p->random = n;
        }
        return new_head;
    }
};
```
