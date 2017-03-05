# Power of Three

标签： math

---
## 题目描述
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

- `push(x)` -- Push element x onto stack.
- `pop()` -- Removes the element on top of the stack.
- `top()` -- Get the top element.
- `getMin()` -- Retrieve the minimum element in the stack.

## 思路分析
这道题要求实现一个能够以$O(1)$时间复杂度获取最小值的栈结构。联系栈后进先出的特点，我们可以再使用一个栈，专门用来记录区间的最小值。记存放数值的栈为`S`，存放最小值的栈为$M$。那么只需满足`M.top = min({x, x \in M})`这个条件的话，每次调用`getMin()`的时候直接返回`M.top`就好了。

如何使得`M`满足这样的性质呢？比如当前状态下`M`已经满足了这样的性质。那么对于新来的元素`x`，如果`x`小于`M.top`，那么将`x`入栈`M`即可。如果`x`大于等于`M.top`，那么将值`M.top`入栈`M`即可。这样，对于增加元素前后保证了`M`的性质。如果是弹出某元素呢？这就更加简单，由于`M.top`始终满足了这样的性质，所以直接弹出`M.top`即可（因为在上一步中，`M.[top-1]`同样是满足这一性质的）。

## 代码

### C++实现
```
class Solution {
    class MinStack {
    private:
        stack<int> numbers_;
        stack<int> min_;
    public:
        /** initialize your data structure here. */
        MinStack() {

        }

        void push(int x) {
            numbers_.push(x);
            if(!min_.empty()) {
                min_.push(min(x, min_.top()));
            } else {
                min_.push(x);
            }
        }

        void pop() {
            numbers_.pop();
            min_.pop();
        }

        int top() {
            return numbers_.top();
        }

        int getMin() {
            return min_.top();
        }
    };
```
### Python实现

```
class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        # python中使用list作为stack
        self.num_stack, self.min_stack = list(), list()

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        self.num_stack.append(x)
        # 注意边界值处理
        self.min_stack.append(x if len(self.min_stack) == 0
                                else min(self.min_stack[-1], x))

    def pop(self):
        """
        :rtype: void
        """
        self.num_stack.pop()
        self.min_stack.pop()

    def top(self):
        """
        :rtype: int
        """
        return self.num_stack[-1]

    def getMin(self):
        """
        :rtype: int
        """
        return self.min_stack[-1]
```
