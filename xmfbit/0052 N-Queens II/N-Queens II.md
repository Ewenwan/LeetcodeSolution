# N-Queens II

标签： back_tracking

---

## 题目描述
Follow up for [N-Queens problem](https://leetcode.com/problems/n-queens/).

Now, instead outputting board configurations, return the total number of distinct solutions.
## 思路分析
N皇后问题是一个典型的可以使用回溯方法解决的问题。在NxN的棋盘上放置皇后，要求不能同行同列同斜线。

```
NQUEEN(int step, int n, State s)
// 对于第step个皇后，我们将它放置在第step行
// 这样我们只需考虑同一列和斜线不能有多个皇后
if step == n   // n个皇后都已经放置合理位置
    得到一组解
for i = 0->n   // 尝试在第0列到最后一列放置第step个皇后
    if 这个位置冲突 
        continue
    // 在当前位置可以放置皇后
    修改s以标记对于后续操作的不可行区域
    NQUEEN(step + 1, n, s)
```

在实际代码中，我们使用一个变量`px`储存已经放置过的皇后的x坐标，那么`step`大小正好是`px.size()`。同时，使用一个变量`mask`标记已经放置过的皇后的列。`mask[j] == true`表示第j列已经放置了皇后。

## 代码
```
class Solution {
    int n;
    void bt(int& cnt, vector<bool>& mask, vector<int>& px) {
        if(px.size() == n) {
            cnt++;
            return;
        }
        for(int j = 0; j < n; ++j) {
            if(mask[j]) continue;
            int k = 0;
            for(; k < px.size(); ++k) {
                if(px[k] - j == k - px.size() || px[k] - j == px.size() - k) break;
            }
            if(k < px.size())   continue;
            mask[j] = true;
            px.push_back(j);
            bt(cnt, mask, px);
            px.pop_back();
            mask[j] = false;
        }
    }
public:
    int totalNQueens(int n) {
        this->n = n;
        vector<bool> mask(n, false);
        int cnt = 0;
        vector<int> px;
        bt(cnt, mask, px);
        return cnt;
    }
};
```



