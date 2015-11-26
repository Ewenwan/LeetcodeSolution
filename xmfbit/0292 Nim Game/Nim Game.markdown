# Nim Game

标签： math

---

## 题目描述
You are playing the following Nim Game with your friend: There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones. The one who removes the last stone will be the winner. You will take the first turn to remove the stones.

Both of you are very clever and have optimal strategies for the game. Write a function to determine whether you can win the game given the number of stones in the heap.

For example, if there are 4 stones in the heap, then you will never win the game: no matter 1, 2, or 3 stones you remove, the last stone will always be removed by your friend. 

## 思路分析
这个问题让我想起了小学时候的一本课外读物《小学生必读》里面的一个故事，阿凡提和国王抓石子。在那个问题里面，每个人只能拿一个或两个石子。阿凡提后拿，那么他的必胜策略就是国王拿n个，他就拿3-n。
这种问题都可以用减而治之的方法来分析。当n<4的时候，可以知道n为1,2,3的时候，先手胜；当n为4的时候，后手胜。那么当n大于4的时候，都可以转换为n小于4的状态。

## 代码
```
class Solution {
public:
    bool canWinNim(int n) {
        return n%4;
    }
};
```




